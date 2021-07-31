#include <iostream>
#include <cstdlib>
#include "FiveNumberSummary.h"
#include "DataSequence.h"
using namespace std;

DataSequence::DataSequence(float *values, int n) //constructor
{
    array = new float[n];
    f = new FiveNumberSummary();
    size = n;
    for (int i = 0; i < size; i++)
    {
        array[i] = values[i];
    }
}
DataSequence::~DataSequence()
{
    delete[] array;
    delete f; //freeing the pointer
}
DataSequence::DataSequence(const DataSequence &s)      //copy constructor
{
     size = s.size;
     array = new float[size];
     f = new FiveNumberSummary();
    for(int i=0;i<s.size;i++)
    {
        array[i] = s.array[i];
    }
    setFiveNumberData();
}

int DataSequence::getSize() //getsize
{
    return size;
}

float *DataSequence::getArray() //return the datasequence
{
    return array;
}

void DataSequence::setSize(int n) //setter for size
{
    size = n;
}

void DataSequence::setArray(float *values) //setter for the array
{
    array = new float[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = values[i];
    }
}

void DataSequence::SortArray() //bubble sort
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                float temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

float DataSequence::getMin() //minimum of the array
{
    SortArray();
    return array[0];
}

float DataSequence::getMean() //mean of the array
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
        sum += array[i];
    return sum / size;
}

float DataSequence::getMeadian() //median of the array
{
    SortArray();
    if (size % 2 != 0)
        return array[size / 2];

    return (array[(size - 1) / 2] + array[size / 2]) / 2.0;
}

float DataSequence::getMax() //maximum of the array
{
    SortArray();
    return array[size - 1];
}
void DataSequence::setHistogram(Histogram &h, int b_size) //association
{
    float max, min, diff;
    if (getMax() == getMin()) //the max and min should be different
    {
        max = getMax() + 0.5;
        min = getMin() - 0.5;
        diff = 1.0 / b_size;
    }
    else //otherwise we have to do the normal functioning
    {
        max = getMax();
        min = getMin();
        diff = (max - min) / b_size;
    }
    float *temp = new float[b_size + 1];
    temp[0] = min;
    for (int i = 1; i < b_size + 1; i++)
    {
        temp[i] = temp[i - 1] + diff;
    }
    h.setBinValues(temp, b_size);
    float *bin_values_arr = new float[b_size + 1];
    for (int i = 0; i <= b_size; i++)
    {
        bin_values_arr[i] = temp[i];
    }
    
    free(temp);
    temp = (float *)calloc(b_size, sizeof(float));
    for (int i = 0; i < b_size; i++)
    {
        temp[i] = 0.0;
    }
    for (int i = 0; i < size; i++)
    {
        int index = (array[i] - getMin()) / diff;
        if (array[i] != getMax())
        {
            temp[index] += 1;
        }
        else
        {
            temp[index - 1] += 1;
        }
    }
    for (int i = 0; i < b_size; i++)
    {
        temp[i] = (float)(temp[i] / (size));
    }
    h.setBinFrequencies(temp, 10);
}

void DataSequence::setFiveNumberData() //setting the values for 5nuber class
{
    SortArray();
    f->setSimpleMinimum(getMin());
    f->setMedian(getMeadian());
    f->setSimpleMaximum(getMax());
    if (size % 2 == 0)
    {
        int p = size / 2;
        if (p % 2 == 0)
        {
            f->setLowerQuartile((array[(p - 1) / 2] + array[p / 2]) / 2.0);
            f->setThirdQuartile((array[((p - 1) / 2) + p] + array[(p / 2) + p]) / 2.0);
        }
        else
        {
            int k = p / 2;
            f->setLowerQuartile(array[k]);
            f->setThirdQuartile(array[p + k]);
        }
    }
    else
    {
        int p = (size / 2) + 1;
        if (p % 2 == 0)
        {
            f->setLowerQuartile((array[(p - 1) / 2] + array[p / 2]) / 2.0);
            f->setThirdQuartile((array[((p - 1) / 2) + p] + array[(p / 2) + p]) / 2.0);
        }
        else
        {
            int k = p / 2;
            f->setLowerQuartile(array[k]);
            f->setThirdQuartile(array[p + k - 1]);
        }
    }
}
ostream &operator<<(ostream &dout, DataSequence d)
{
    dout << *(d.f);
    return (dout);
}