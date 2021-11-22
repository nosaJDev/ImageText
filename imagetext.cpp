#include "imagetext.hpp"
#include <cstdio>
#include <cmath>
//lodepng_decode32_file(unsigned char** out, unsigned* w, unsigned* h,
//                               const char* filename);

ImageText::ImageText(const char * filename){

    // Decode the file into an array of data
    lodepng_decode24_file(&imagedata,&width,&height,filename);

    // Set the divisors to get smaller images
    wdiv = width/maxwidth;
    hdiv = height/maxheight;
    wdiv = (wdiv < 1)?1:wdiv;
    hdiv = (hdiv < 1)?1:hdiv;

    printf("width of %d height of %d\n",width,height);

    if(imagedata == nullptr){
        printf("Error loading image\n");
    }
    
    printf("Correct loading\n");
    fflush(stdout);

}

ImageText::~ImageText(){

    // Delete the image data
    delete[] imagedata;

}

void ImageText::set_pallete_tempstring(char * pallete, int pallete_no, int pallete_get){

    // This will combine the simple pallete colors into more
    // and save the result temporarily into a tempstring

    // Set the boundaries
    int actual_pallete_no = pallete_no*2-1;
    if(pallete_get >= actual_pallete_no) pallete_get = actual_pallete_no-1;
    if(pallete_get < 0) pallete_get = 0;

    // Then set the color according to pallete get
    tempstring[0] = pallete[pallete_get/2];
    tempstring[1] = pallete[(pallete_get/2)+(pallete_get%2)];
    tempstring[2] = 0;

}

void ImageText::print_file(const char * filename, char * pallete,int pallete_no){

    // This will print the image to a file following specific protocol of the parameters

    // Open the file for printing
    FILE * file = fopen(filename,"w");
    if(file == nullptr){
        printf("Could not open output file\n");
        return;
    }

    // Then loop through the image and print to the file
    for(int i = 0; i < width*height; i+=1){
        
        if(i%width == 0){
            fprintf(file,"\n");
            
        }

        // Get the rgb color
        unsigned char red = imagedata[3*i];
        unsigned char green = imagedata[3*i+1];
        unsigned char blue = imagedata[3*i+2];

        // Find the luminosity value
        int lum = ((int)red+green+blue)/3;
        float real_lum = lum/256.0;

        // Find the pallete color get
        int pallete_get = (int)floor((pallete_no*2-1)*real_lum);

        // Set the pallete color
        set_pallete_tempstring(pallete,pallete_no,pallete_get);

        // Write the next character
        fprintf(file,"%s",tempstring);

    
        
        
    }

    // Finally close the file
    fclose(file);

}