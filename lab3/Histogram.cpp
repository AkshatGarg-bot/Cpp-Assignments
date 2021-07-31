#include<iostream>
#include <iomanip>
#include<cstdlib>
#include<cmath>
#include"Histogram.h"
using namespace std;
inline float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;  }

Histogram::Histogram(int n)  //constructor
{ 
    bin_size = n;
    bin_values = (float*)calloc(100000, sizeof(float));
    bin_frequency = (float*)calloc(100000, sizeof(float));
} 
// Histogram::~Histogram()  //destructor
// {
//     free(bin_frequency); //freeing the pointers
//     free(bin_values);
// }
// Histogram:: Histogram(Histogram &h)        //copy constructor
// {
//     bin_size = h.bin_size;
//     for(int i=0;i<=bin_size;i++)
//     {
//         bin_values[i] = h.bin_values[i];
//     }
//     for(int i=0;i<bin_size;i++)
//     {
//         bin_frequency[i] = h.bin_frequency[i];
//     }
// }
int Histogram::getBinSize()
{
    return bin_size;
}
float* Histogram::getBinValues()
{
    return bin_values;
}
float* Histogram::getBinFrequency()
{
    return bin_frequency;
}
void Histogram::setBinsize(int n)
{
    bin_size = n;
}
void Histogram::setBinValues(float *arr,int b_size)
{
    bin_values = (float*)calloc(100000, sizeof(float));
    for(int i=0;i<=b_size;i++)
    {
        bin_values[i] = arr[i];
    }
}
void Histogram::setBinFrequencies(float *arr,int b_size)
{
    bin_frequency = (float*)calloc(100000, sizeof(float));
    for(int i=0;i<b_size;i++)
    {
        bin_frequency[i] = arr[i];
    }
}
ostream& operator<<(ostream &dout,Histogram h) //friend function
{
    for(int i=0;i<h.getBinSize();i++)
    {
        dout.precision(4);
        float f = truncfunc(h.getBinValues()[i]);
        //f = (f*10000)*0.0001; 
        dout<<fixed<<f<<",";
    }
    dout.precision(4);
    float f = truncfunc(h.getBinValues()[h.getBinSize()]) ; 
    dout<<fixed<<f;
    dout<<" ";
    for(int i=0;i<h.getBinSize()-1;i++)
    {
        dout.precision(4);
        float f =truncfunc(h.getBinFrequency()[i]) ;
        //f = (f*10000)*0.0001; 
        dout<<fixed<<f<<"," ;
    }
    dout.precision(4);
    float y =truncfunc(h.getBinFrequency()[h.getBinSize()-1]);
    //y = (y*10000)*0.0001;     
    dout<<fixed<<y<<" ";
    return(dout);
}

