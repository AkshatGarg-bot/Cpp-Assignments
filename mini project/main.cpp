#include<bits/stdc++.h>
#include<fstream>
#include "ModFile.h"
#include "PPMImage.h"


using namespace std;

int main()
{
    string inputFile,outputFile ;
    cout<<"Enter source file name with type(.ascii.ppm):- ";
    cin>>inputFile;
    cout<<"Enter output file with type(.ascii.pgm):-";
    cin>>outputFile;
    PPMImage *m = new PPMImage(inputFile,outputFile);
    m->ModifyFile();
    cout<<"Your file has been converted and saved successfully with name "<<outputFile;
    return 0;
}
