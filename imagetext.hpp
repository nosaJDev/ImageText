#ifndef _itext_
#define _itext_
#include "lodepng.hpp"

class ImageText{

    // This class will load an image from a file, get a
    // pallette from the user and print the image to a 
    // text file, essentially creating ascii art

    private:

        int maxwidth = 500, maxheight = 400;
        int wdiv = 1, hdiv = 1;
        unsigned int width,height;
        unsigned char * imagedata;

        char tempstring[3];
        void set_pallete_tempstring(char *, int, int);

    public:

        ImageText(const char *);
        ~ImageText();

        void print_file(const char *, char *, int );



};

#endif