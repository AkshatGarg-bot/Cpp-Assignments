#include<iostream>
#include<cstdlib>
#include <iomanip>
#include<cstring>
#include<cmath>
#include<bits/stdc++.h>
#include"DataSequence.h"
#include"Histogram.h"
using namespace std;

inline float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;}
bool Input_check (float *,char [],long long int *,long long int *);
int main()
{
    long long int n = INT_MAX;       //intializing n to a max value we will change it later
    long long int bin_size = INT_MAX;    //same thing with bin_Size 
    char str[1000];              //character array used to take the input of the program
    cin.getline(str,sizeof(str));  //input
    float *values = (float*)calloc(1000, sizeof(float));  //stores the n float values 
    //Input check function checks whether we have provided the correct input of the program    
    if(Input_check(values,str,&n,&bin_size))     //if true
    {
        DataSequence *d = new DataSequence(values,n);    //creating a data sequence d with the given values
        d->SortArray(values,n);     
        cout.precision(4);
        float a = d->getMin(values,n);
        float b = d->getMean(values,n);
        float c = d->getMeadian(values,n);
        float de = d->getMax(values,n);
        a = truncfunc(a);
        b = truncfunc(b);
        c = truncfunc(c);
        de = truncfunc(de);
        cout<<fixed<<a<<" -1 "<<b<<" -1 "<<c<<" -1 "<<de;
        cout<<" -1 ";
        Histogram *h = new Histogram(bin_size);
        float *temp  = d->getBinValues(values,n,bin_size);
        int *temp1 = d->getBinFreq(values,n,bin_size);
        h->setBinValues(temp,bin_size);
        h->setBinFrequencies(temp1,bin_size);
        h->print_binValues();
        cout<<" -1 ";
        h->print_BinFrequencies();
        cout<<" -1";
        delete h;
        delete d;
    }
    else
    {
        cout<<" -1";
        return 0;
    }
    return 0;
}


//Input check funtion
bool Input_check(float *values,char str[],long long int *n,long long int *bin_size)
{
    int length = strlen(str);
    int spaces = 1;
    int index_values = 0,index=0;;
    int delimiter; 
    char *value = (char*)calloc(20, sizeof(char)); //a temporary substorage which stores all the values whether it is sequence or delimiter
    for(int i=0;i<=length;i++)
    {
        if(i == length)        // This means that we have reached the last character of the input string.
        {
            int l = strlen(value);          
            if(value[l-1] == '-')         //handeling the cases that the last index cant be a - sign
            {
                return false;
            }
            for(int i=0;i<l;i++)
            {
                if((int)value[i]<48 || (int)value[i]>57)       //any other ascii value other than -1
                {
                    if((int)value[i] != '-')
                    {
                        return false;
                    }
                }
            }
            delimiter = atoi(value);
            if(delimiter != -1)                   //value of delimiter should be -1
            {
                return false;
            }
            free(value);
        }
        else if(str[i] == ' ' && spaces == 1)      //this is the first number and should be n
        {
            int l = strlen(value); 
            if(value[l-1] == '.')               //assuming 2.000 as the correct input of n (if the last index is . then it is wrong)
            {
                return false;
            }
            for(int i=0;i<l;i++)
            {
                if((int)value[i]<48 || (int)value[i]>57)     //any other character instead of numbers
                {
                    if((int)value[i] != 46)      //ascii value of a dot
                    { 
                        return false;
                    }
                }
            }
            float temp = atof(value);
            long long int variable = temp;
            *n = variable;
            float p = temp - (float)*n;    
            if(*n<=0 || p>0)    //checking the values of n and p whther
            {
                return false;
            }
            spaces++;
            free(value); 
            value = (char*)calloc(20, sizeof(char));
            index = 0;
        }
        else if(str[i] == ' ' && spaces == 2)    // Between the first and the second space in the input string should be the first delimiter as holding the value -1.
        { 
            int l = strlen(value);
            if(value[l-1] == '-')
            {
                return false;
            }
            for(int i=0;i<l;i++)
            {
                if((int)value[i]<48 || (int)value[i]>57)
                {
                    if((int)value[i] != '-')
                    {
                        return false;
                    }
                }
            }
            delimiter = atoi(value);
            if(delimiter != -1)
            {
                return false;
            }
            spaces++;
            free(value); 
            value = (char*)calloc(20, sizeof(char));
            index = 0;

        }
        else if(str[i] == ',' && spaces == 3)     //this will hold the data sequence
        {
            int l = strlen(value);
            if(value[l-1] == '.')
            {
                return false;
            }
            for(int i=0;i<l;i++)
            {
                if((int)value[i]<48 || (int)value[i]>57)
                {
                    if((int)value[i] != 46)
                    {
                        return false;
                    }
                }
            }
            float temp = atof(value);
            if(temp<=0)                   // If the component of the vector entered by the user is not a decimal number or its less 0, then its an invalid input NOT complying with the norms of input format.
            {
                return false;
            }
            values[index_values++] = temp;
            free(value); 
            value = (char*)calloc(20, sizeof(char));
            index = 0;
        }
        else if(str[i] == ' ' && spaces == 3)
        {
            int l = strlen(value);
            if(value[l-1] == '.')
            {
                return false;
            }
            for(int i=0;i<l;i++)
            {
                if((int)value[i]<48 || (int)value[i]>57)
                {
                    if((int)value[i] != 46)
                    {
                        return false;
                    }
                }
            }
            float temp = atof(value);
            if(temp<=0)
            // If the component of the vector entered by the user is not a decimal number or less than 0, then its an invalid input NOT complying with the norms of input format.
            {
                return false;
            }
            values[index_values++] = temp;
            spaces++;
            free(value); 
            value = (char*)calloc(20, sizeof(char));
            index = 0;
        }
        //similar conditions for -1
        else if(str[i] == ' ' && spaces == 4)
        { 
            int l = strlen(value);
            if(value[l-1] == '-')
            {
                return false;
            }
            for(int i=0;i<l;i++)
            {
                if((int)value[i]<48 || (int)value[i]>57)
                {
                    if((int)value[i] != '-')
                    {
                        return false;
                    }
                }
            }
            delimiter = atoi(value);
            if(delimiter != -1)
            {
                return false;
            }
            spaces++;
            free(value); 
            value = (char*)calloc(20, sizeof(char));   
            index = 0;
        }
        else if(str[i]==' ' && spaces == 5)      //this will have the bin size and will be done correspondingly
        {
            float temp = atof(value);
            long long int variable = temp;
            *bin_size = variable;
            float p = temp - (float)*bin_size;
            if(*bin_size <= 0 || p>0.0)
            {
                return false;
            }
            free(value); 
            value = (char*)calloc(20, sizeof(char));
            index = 0;
        }
        else
        {
            value[index++] = str[i];
        }
        
    }
    return *n==index_values && spaces ==5;
}