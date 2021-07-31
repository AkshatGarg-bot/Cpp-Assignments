#ifndef BINOMIAL
#define BINOMIAL
using namespace std;
#include<iostream>
#include"Histogram.h"
class BinomialDistribution : public Histogram{
    private:
        int n;
        double probablity;
    public:
        BinomialDistribution(int ,double); //constructor
        ~BinomialDistribution() //destructor
        {}
        BinomialDistribution(const BinomialDistribution &b)    //copy constructor
        {
            n = b.n;
            probablity = b.probablity;
        }
        void makeArray(); //make array of pmf
        void setN(int); //setter
        void setProbab(double probablity); //settter
        int getN(); //getter
        double getProbab(); //getter
       double nCr(int,int); //nCx
};
#endif