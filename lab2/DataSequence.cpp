#include<iostream>
#include<cstdlib>
#include"DataSequence.h"
#include"Histogram.h"
using namespace std;

DataSequence::DataSequence(float *values,int n) //constructor
{
    array = (float*)calloc(n, sizeof(float)); 
    size = n;
    for(int i=0;i<size;i++)
    {
        array[i] = values[i];
    }
    for(int i=0;i<size;i++)
    {
        array[i] = values[i];
    }
}
DataSequence::DataSequence(const DataSequence &s)      //copy constructor
{
    size = s.size;
    array = (float*)calloc(size, sizeof(float));
    for(int i=0;i<size;i++)
    {
        array[i] = s.array[i];
    }
}

int DataSequence::getSize()     //getsize
{
    return size;
}

float* DataSequence::getArray()    //return the datasequence
{
    return array;
}

void DataSequence::setSize(int n)   //setter for size
{ 
    size = n;
}

void DataSequence::setArray(float *values)      //setter for the array
{
    array = (float*)calloc(size, sizeof(float));
    for(int i=0;i<size;i++)
    {
        array[i] = values[i];
    }
}

void DataSequence::SortArray(float *array,int size)     //bubble sort
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                float temp = array[j];
                array[j] = array[j+1];
                array[j+1]=temp;
            }
        }
    }
}

float DataSequence::getMin(float *array,int size)        //minimum of the array
{
    SortArray(array,size);
    return array[0];
}

float DataSequence::getMean(float *array,int size)     //mean of the array
{
    double sum = 0.0; 
    for (int i = 0; i < size; i++)  
        sum += array[i];   
    return sum/size; 
}

float DataSequence::getMeadian(float *array,int size)      //median of the array
{
    SortArray(array,size);
    if (size % 2 != 0) 
        return array[size/2]; 

    return (array[(size-1)/2] + array[size/2])/2.0;
}

float DataSequence::getMax(float *array,int size)  //maximum of the array
{
    SortArray(array,size);
    return array[size-1];
}

float* DataSequence::getBinValues(float *array,int size,int b_size)           //creates the bin values 
{ 
    float max,min,diff;
    if(getMax(array,size) == getMin(array,size))    //the max and min should be different
    {
        max =  getMax(array,size)+0.5;
        min =  getMin(array,size)-0.5;
        diff = 1.0/b_size;
    }
    else                 //otherwise we have to do the normal functioning
    {
        max =  getMax(array,size);
        min =  getMin(array,size);
        diff = (max - min)/b_size;   
    }
    float *temp = (float*)calloc(b_size+1, sizeof(float));
    temp[0] = min;
    for(int i=1;i<b_size+1;i++)
    {
        temp[i] = temp[i-1]+diff;
    }
    return temp;
}
        
        
int* DataSequence::getBinFreq(float *array,int size,int b_size)     //creates the bin frequencies
{
    float *bin_values_arr = getBinValues(array,size,b_size);
    int *temp = (int*)calloc(b_size, sizeof(int));
    for(int i=0;i<b_size;i++)
    {
        temp[i]=0;
    }
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<b_size;j++)
        {
            if(array[i]>=bin_values_arr[j] && array[i]<bin_values_arr[j+1])
            {
                temp[j]=temp[j]+1;
            }
            if(array[i] == bin_values_arr[j+1] && j+1 == b_size)
            {
                temp[j]++;
            }
        }
    }
    return temp;
}