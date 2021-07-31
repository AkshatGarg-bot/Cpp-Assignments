#ifndef HISTOGRAM
#define HISTOGRAM
#include<cstdlib>
class Histogram{
    private:
        int bin_size;                //stores the binsize
        float *bin_values;          //stores the bin values
        int *bin_frequency;          //stores the bin frequencies
    public:
        Histogram(int n);
        ~Histogram();
        Histogram(const Histogram &h);
    public:
        int getBinSize();
        float* getBinValues();
        int* getBinFrequency();
        void setBinsize(int n);
        void setBinValues(float *arr,int b_size);
        void setBinFrequencies(int *arr,int b_size);
    public:
        void print_binValues();
        void print_BinFrequencies();
        friend inline float truncfunc(float x);
};
#endif