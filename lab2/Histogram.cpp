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
    bin_frequency = (int*)calloc(100000, sizeof(int));
} 
Histogram::~Histogram()  //destructor
{
    free(bin_frequency); //freeing the pointers
    free(bin_values);
}
Histogram:: Histogram(const Histogram &h)        //copy constructor
{
    bin_size = h.bin_size;
    bin_values = (float*)calloc(100000, sizeof(float));
    bin_frequency = (int*)calloc(100000, sizeof(int));
    for(int i=0;i<=bin_size;i++)
    {
        bin_values[i] = h.bin_values[i];
    }
    for(int i=0;i<bin_size;i++)
    {
        bin_frequency[i] = h.bin_frequency[i];
    }
}
int Histogram::getBinSize()
{
    return bin_size;
}
float* Histogram::getBinValues()
{
    return bin_values;
}
int* Histogram::getBinFrequency()
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
void Histogram::setBinFrequencies(int *arr,int b_size)
{
    bin_frequency = (int*)calloc(100000, sizeof(int));
    for(int i=0;i<b_size;i++)
    {
        bin_frequency[i] = arr[i];
    }
}
void Histogram::print_binValues()
{
    cout.precision(4);
    for(int i=0;i<bin_size;i++)
    {
        float f = truncfunc(bin_values[i]) ;
        cout<<fixed<<f<<",";
    }
    float f = truncfunc(bin_values[bin_size]);
    cout<<fixed<<f;
} 
void Histogram::print_BinFrequencies()
{
    for(int i=0;i<bin_size-1;i++)
    {
        cout<<bin_frequency[i]<<"," ;
    }
    cout<<bin_frequency[bin_size-1];
}
