#ifndef DATASEQUENCE
#define DATASEQUENCE
#include<iostream>
using namespace std;
class DataSequence{
    private:
        float *array;   //stores the data sequence
        int size;      //size of the data sequnce
    public:    
        DataSequence(float *values,int n);
        ~DataSequence()
        {
            free(array);        //freeing the pointer 
        };
        DataSequence(const DataSequence &s);
    public:
        int getSize();
        float* getArray();
        void setSize(int n);
        void setArray(float *values);
    public:
        void SortArray(float *array,int size);
        float getMin(float *array,int size);
        float getMean(float *array,int size);
        float getMeadian(float *array,int size);
        float getMax(float *array,int size);
        float* getBinValues(float *array,int size,int b_size);
        int* getBinFreq(float *array,int size,int b_size);
};
#endif