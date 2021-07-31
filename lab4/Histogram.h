#ifndef HISTOGRAM
#define HISTOGRAM
#include<cstdlib>
#include<iostream>
using namespace std;
class Histogram{
    private:
        int bin_size;                //stores the binsize
        double *bin_values;          //stores the bin values
        double *bin_frequency;          //stores the bin frequencies
        double *array;
    public:
        Histogram(int n); //constructor
        Histogram(){ //default constructor

        }
        ~Histogram() //destructor
        {
            delete []bin_frequency;
            delete []bin_values;
            delete []array;
        }
        Histogram(const Histogram &h) //copy constructor
        {
            bin_size = h.bin_size;
            array = new double[bin_size];
            for(int i = 0;i<bin_size;i++)
            {
                array[i] = h.array[i];
            }
        }
        int getBinSize(); //getters
        double* getBinValues();
        double* getBinFrequency();
        double* getArray();
        //setters
        void setBinsize(int n);
        void setBinValues(double *arr,int b_size);
        void setBinFrequencies(double *arr,int b_size);
        void SetArray(double *arr,int b_size);
        //distances which are friend functions
        friend double Manhattandistance(double *v1 , double *v2,int l);
        friend double Euclideandistance(double *v1 , double *v2,int l);
        friend double Chebyshevdistance(double *v1 , double *v2,int l);
        friend double KLdiv(double *v1 , double *v2,int l);
        friend double KL(double *v1 , double *v2,int l);
        friend double JSdistance(double *v1 , double *v2,int l);
        friend int difference(Histogram,Histogram);
        friend ostream& operator<<(ostream&,Histogram);
        friend inline float truncfunc(float x);
};
#endif