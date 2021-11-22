#include <cstdio>
#include <cstdlib>
#include "imagetext.hpp"

int main(){

    char pallete[8] = "8KPOo ";

    printf("Hello World\n");
    
    ImageText * converter = new ImageText("test.png");

    converter->print_file("test.txt",pallete,6);


    return 0;
}