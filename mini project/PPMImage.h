#ifndef PPMIMAGE
#define PPMIMAGE
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include "ModFile.h"

using namespace std;

class PPMImage:public ModFile{ // inherits from modfile
    private:
    vector<int> grayscale_pgm;
    int width; //width of file
    int height;//height of file
    string magicno;//magic number of ppm
    int maxvalue;//max colour value
    public:
        PPMImage(string,string); // takes input and output filepath
        ~PPMImage(){}
        void ModifyFile(); // wrapper function which calls all required functions to modify
        int getWidth(); //returns width of image
        void setWidth(int p);//setter for width
        int getHeight(); //return height of image
        void setHeight(int p); //sets height
        void add(int p);//adds into grayscale vector
        void setMagicNo(string s);//setter for magic number
        string getMagicNo(); //returns magic number
        void setMax(int p); //sets maximum colour value
        int getMax(); //returns maximum colour value
        vector<int> getGrayScale(); //return the array
        void output(); //output the file
        void toGrayscale(); //converts to grayscale

};
#endif
