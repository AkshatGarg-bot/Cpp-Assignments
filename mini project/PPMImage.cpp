#include"PPMImage.h"

#include<bits/stdc++.h>

using namespace std;

PPMImage::PPMImage(string inputfile, string outputfile){
    this->setinputFilePath(inputfile);
    this->setoutputFilePath(outputfile);
}

void PPMImage::ModifyFile(){
    toGrayscale();
    output();
}


void PPMImage::toGrayscale()
{
    int width,height;
	int max_peak;
	fstream RW; //used for read and write
	RW.open(this->getinputFilePath()); //opening the file
    if(RW.is_open()){ //check if file is there or not
		string garbage;//magnos comments
		if(RW.peek()=='#') //if it contains a # then it is a comment
        {
            getline(RW,garbage); //so we magno that line in the string
        }
		string magno; //magnos the magic number
		int r,g,b; //rgb values
		getline(RW,magno);
        if(RW.peek()=='#')
        {
            getline(RW,garbage);
        }
        setMagicNo(magno);
		if(RW.peek()=='#')
        {
            getline(RW,garbage);
        }
		RW >> width >> height >> max_peak;  //gets height width and max from the  ppm file
		setWidth(width); //setting all the values
        setHeight(height);
        setMax(max_peak);
        if(magno == "P3"){ //if p3 is there then its a ppm file

		    while(RW >> r){

		        RW >> g >> b;
				add((0.3 * r) + (0.59 * g) + (0.11 * b));
			}

    	}
		else{
			cout<<"Enter the correct file format";
			exit(0);
		}
	}
	else
	{
		cout<<"File not present";
		exit(0);
	}

    RW.close();
}
void PPMImage::output()
{
	fstream RW; //setting another fstream

	RW.open(this->getoutputFilePath(),ios::out); //writing to computer

    int h = getHeight();
    int w = getWidth();
	RW << "P2" << endl << w << " " << h << endl << getMax() << endl; //using getters
	vector<int> g = getGrayScale(); //getting array
	for(int i=0;i < h*w;i++)
	{
        RW << g[i]<< "  ";

		if((i + 1) % w == 0){ //changing line when one row is over
			RW << endl;
		}

	}

	RW.close();
}

int PPMImage::getWidth()
{
	return width;
}
void PPMImage::setWidth(int p)
{
	width = p;
}
int PPMImage::getHeight()
{
	return height;
}
void PPMImage::setHeight(int p)
{
	height = p;
}
void PPMImage::add(int p)
{
	grayscale_pgm.push_back(p);
}
void PPMImage::setMagicNo(string s)
{
	magicno = s;
}
string PPMImage::getMagicNo()
{
	return magicno;
}
void PPMImage::setMax(int p)
{
	maxvalue = p;
}
int PPMImage::getMax()
{
	return maxvalue;
}
vector<int> PPMImage::getGrayScale()
{
	return grayscale_pgm;
}
