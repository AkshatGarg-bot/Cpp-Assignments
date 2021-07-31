#ifndef DATASEQUENCE
#define DATASEQUENCE
using namespace std;
#include"FiveNumberSummary.h"
#include"Histogram.h"
class DataSequence
{
    private:
        float *array;   //stores the data sequence
        int size;      //size of the data sequnce
        FiveNumberSummary *f;
    public:    
         DataSequence(float *values,int n);
        ~DataSequence();
         DataSequence(const DataSequence &s);
    public:
        int getSize();
        float* getArray();
        void setSize(int n);
        void setArray(float *values);
    public:
        void SortArray();
        float getMin();
        float getMean();
        float getMeadian();
        float getMax();
        void setHistogram(Histogram &h,int b_size);
        void setFiveNumberData();
        friend ostream& operator<<(ostream&,DataSequence);
        
        
};
#endif