#include<iostream>
#include <sstream>
#include <iomanip>
#include<cstring>
#include<cmath>
#include"BinomialDistribution.h"
#include"Histogram.h"
using namespace std;
bool checker(char str[]) //checks whether there is a different charater or not like - @ # and all of these
{
    int l = strlen(str);
    for(int i=0;i<l;i++)
    {
        if((int)str[i]<32)
        {
            return false;
        }
        else if((int)str[i]>32 && (int)str[i]<=45)
        {
            return false;
        }
        else if((int)str[i]==47)
        {
            return false;
        }
        else if((int)str[i]>=48 && str[i]<58)
        {}
        else if((int)str[i]==46 || (int)str[i]==32)
        {}   
        else
        {
            return false;
        }
    }
    return true;
}
bool input(char str[],int *n,double *p1,double *p2) //checks for the input considering all the values
{
    if(checker(str)==false)          //checking special characters
    {
        return false;
    }
    char *value = (char*)calloc(20, sizeof(char));    //substring to store the subparts of the string
    int space = 0,index = 0;             //keeps a track fo spaces and index of the substring
    int length = strlen(str);
    for(int i=0;i<=length;i++)
    { 
        if(i == length)      //finally we have a substring which corresponds to p2
        {
            int count  = 0;     //count the dots in the substinrg
            int l = strlen(value);
            for(int j=0;j<l;j++)
            {
                if((int)value[j] == 46) //46 is the ascii value of "."
                {
                    count++;
                }   
            }
            if(count != 1)
            {
                return false;
            }
            double var = atof(value);
            if(var<=0 || var>=1)
            {
                return false;
            }
            else 
            {
                *p2 = var;
            }
            free(value);
            index = 0;
            value = (char*)calloc(20, sizeof(char));
        }
        else if(space == 0 && str[i]==' ') //scans  the first n
        {
            space++;
            int l = strlen(value);
            for(int j=0;j<l;j++)
            {
                
                if(value[j]<48 || value[j]>57) //checks for any other character except integer
                {
                   return false;
                }
            }
            int p = atoi(value);
            if(p<=0)
            {
                return false;
            }
            else
            {
                *n  = p;
            }
            free(value);
            index = 0;
            value = (char*)calloc(20, sizeof(char));
        } 
        else if(space==1 && str[i]==' ') //checks for p1
        {
            space++;
            int count  = 0;
            int l = strlen(value);
            for(int j=0;j<l;j++)
            {
                if(value[j] == '.')
                {
                    count++;
                }   
            }
            if(count != 1)
            {
                return false;
            }
            double var = atof(value);
            if(var<=0 || var>=1)
            {
                return false;
            }
            else 
            {
                *p1 = var;
            }
            free(value);
            index = 0;
            value = (char*)calloc(20, sizeof(char));
        }
        else
        {
            value[index++] = str[i];
        }
    }
    return true;
}
int main()
{
    int n = 0;
    double p1 = 0.0;
    double p2 = 0.0;
    char str[10000];
    cin.getline(str,sizeof(str));
    if(input(str,&n,&p1,&p2))
    {
        BinomialDistribution *b1 = new BinomialDistribution(n,p1); //binomail distribution object
        BinomialDistribution *b2 = new BinomialDistribution(n,p2);
        b1->makeArray(); //making the PMF ARRAY
        b2->makeArray();
        Histogram *H1 = b1; //UPCASTING
        Histogram *H2 = b2;
        if(difference(*H1,*H2)==-1) //finding the distance
        {
            cout<<"-1";
        }
    }
    else
    {
        cout<<"-1";
    }
    
    return 0;
}