#include<iostream>
#include <bits/stdc++.h> 
#include"BinomialDistribution.h"
BinomialDistribution::BinomialDistribution(int size,double pro)
{
    n = size;
    probablity = pro;
    Histogram::setBinsize(n+1);
}
int BinomialDistribution::getN()
{
    return n;
}
void BinomialDistribution::setN(int size)
{
    n = size;
}
void BinomialDistribution::setProbab(double pro)
{
    probablity = pro;
}
double BinomialDistribution::getProbab()
{
    return probablity;
}
double BinomialDistribution :: nCr(int n,int r){
    double num = 1,temp = 1;
    for(int i=0;i<r;i++){
        num *= (n-i);
        temp *= (r-i);
    }
    return num/temp;
}
void BinomialDistribution::makeArray()
{
    double *f = new double[n+1]; //array declaration
    for(int i=0;i<n+1;i++)
    {
        f[i] = (nCr(n,i))*pow(probablity,i)*pow(1-probablity,n-i); //formula
    }
    Histogram::setBinsize(n+1); //setbins
    Histogram::SetArray(f,n);   //set array
}