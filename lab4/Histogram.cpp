#include<iostream>
#include <iomanip>
#include<cstdlib>
#include <cmath>
#include"Histogram.h"
using namespace std;
inline float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;  }
Histogram::Histogram(int n)  //constructor
{ 
    bin_size = n;
    bin_values = new double[bin_size+1];
    bin_frequency = new double[bin_size];
} 
int Histogram::getBinSize()
{
    return bin_size;
}
double* Histogram::getBinValues()
{
    return bin_values;
}
double* Histogram::getBinFrequency()
{
    return bin_frequency;
}
double* Histogram::getArray()
{
    return array;
}
void Histogram::setBinsize(int n)
{
    bin_size = n;
}
void Histogram::setBinValues(double *arr,int b_size)
{
    bin_values = new double[b_size+1];
    for(int i=0;i<=b_size;i++)
    {
        bin_values[i] = arr[i];
    }
}
void Histogram::setBinFrequencies(double *arr,int b_size)
{
    bin_frequency = new double[b_size];
    for(int i=0;i<b_size;i++)
    {
        bin_frequency[i] = arr[i];
    }
}
void Histogram::SetArray(double *arr,int b_size)
{
    array = new double[b_size+1];
    for(int i=0;i<=b_size;i++)
    {
        array[i] = arr[i];
    }   
}
double Manhattandistance(double *v1 , double *v2,int n)
{
    double distance = 0.0;
    for(int i=0;i<n;i++)
    {
        distance += fabs(v1[i]-v2[i]);
    }
    return distance;
}
double Euclideandistance(double *v1 , double *v2,int n)
{
    double distance = 0.0;
    for(int i=0;i<n;i++)
    {
        distance += pow((v1[i]-v2[i]),2);
    }
    distance = sqrt(distance);
    return distance;

}
double Chebyshevdistance(double *v1 , double *v2,int n)
{
    double distance = 0.0;
    for(int i=0;i<n;i++)
    {
        if(distance< fabs(v1[i]-v2[i]))
        {
            distance = fabs(v1[i]-v2[i]);
        }
    }
    return distance;
}
double KLdiv(double *v1 , double *v2,int n)
{
    double distance = 0.0;
    for(int i=0;i<n;i++)
    {
        distance += (v1[i])*(log(v1[i]/v2[i]));
    }
    for(int i=0;i<n;i++)
    {
        distance += (v2[i])*(log(v2[i]/v1[i]));
    }
    return distance;
}
double KL(double *v1 , double *v2,int n)
{
    double distance = 0.0;
    for(int i=0;i<n;i++)
    {
        distance += (v1[i])*(log(v1[i]/v2[i]));
    }
    return distance;
}
double JSdistance(double *v1 , double *v2,int n)
{
    double distance=0.0;
    double mid[n];
    for(int i=0;i<n;i++)
    {
        mid[i]=(v1[i]+v2[i])/2;
    }
    double p1 = KL(v1,mid,n);
    double p2 = KL(v2,mid,n);
    distance += (p1+p2)/2;
    distance = sqrt(distance);
    return distance;
}
int difference(Histogram h1 , Histogram h2)
{
    if(h1.getBinSize()==h2.getBinSize())
    {   
        int p = h1.getBinSize();
        double *v1 = h1.getArray();
        double *v2 = h2.getArray();
        double va1 = Manhattandistance(v1,v2,p);
        double va2 =Euclideandistance(v1,v2,p);
        double va3 = Chebyshevdistance(v1,v2,p);
        double va4 = KLdiv(v1,v2,p);
        double va5 = JSdistance(v1,v2,p);
        cout.precision(4);
        va1 = truncfunc(va1);
        va2 = truncfunc(va2);
        va3 = truncfunc(va3);
        va4 = truncfunc(va4);
        va5 = truncfunc(va5);
        cout<<fixed<< va1 << " "<<va2<<" "<<va3<<" "<<va4<<" "<<va5; 
        return 1;
    }
    else
    {
        cerr<<"Bin size is not same";
        return -1;
    }
    
}
ostream& operator<<(ostream &dout,Histogram h) //friend function
{
    for(int i=0;i<h.getBinSize();i++)
    {
        dout<<h.getBinValues()[i]<<",";
    }
    dout<<h.getBinValues()[h.getBinSize()];
    dout<<" ";
    for(int i=0;i<h.getBinSize()-1;i++)
    {
        dout<<h.getBinFrequency()[i]<<"," ;
    }
    dout<<h.getBinFrequency()[h.getBinSize()-1]<<" ";
    return(dout);
}