#ifndef HISTOGRAM
#define HISTOGRAM
#include<cstdlib>
#include<iostream>
using namespace std;
class Histogram{
    private:
        int bin_size;                //stores the binsize
        float *bin_values;          //stores the bin values
        float *bin_frequency;          //stores the bin frequencies
    public:
        Histogram(int n);
       // ~Histogram();
        // {
        //     free(bin_values);
        //     free(bin_frequency);
        // }
        // Histogram(const Histogram &h);
        int getBinSize();
        float* getBinValues();
        float* getBinFrequency();
        void setBinsize(int n);
        void setBinValues(float *arr,int b_size);
        void setBinFrequencies(float *arr,int b_size);
        friend ostream& operator<<(ostream&,Histogram);
        friend inline float truncfunc(float x);

};
#endif