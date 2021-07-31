#include<iostream>
#include"FiveNumberSummary.h"
#include <cmath>

using namespace std;
inline float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;  }

FiveNumberSummary::FiveNumberSummary(float v1,float v2,float v3,float v4, float v5) //constructors
{
    simpleminimum = v1;
    lowerquartile = v2;
    median = v3;
    thirdquartile = v4;
    simplemaximum = v5;
}
FiveNumberSummary::FiveNumberSummary()
{}
FiveNumberSummary::FiveNumberSummary(const FiveNumberSummary &f)
{
    simpleminimum = f.simpleminimum;
    simplemaximum = f.simplemaximum;
    lowerquartile = f.lowerquartile;
    median = f.median;
    thirdquartile = f.thirdquartile; 
}
void FiveNumberSummary::setSimpleMinimum(float val)
{
    simpleminimum = val;
}
void FiveNumberSummary::setLowerQuartile(float val)
{
    lowerquartile = val;
}

void FiveNumberSummary::setMedian(float val)
{
    median = val;
}
void FiveNumberSummary::setThirdQuartile(float val)
{
    thirdquartile = val;
}
void FiveNumberSummary::setSimpleMaximum(float val)
{
    simplemaximum = val;
}
float FiveNumberSummary::getSimpleMinimum()
{
    return simpleminimum;
}
float FiveNumberSummary::getFirstQuartile()
{
    return lowerquartile;
}
float FiveNumberSummary::getMedian()
{
    return median;
}
float FiveNumberSummary::getThirdQuartile()
{
    return thirdquartile;
}
float FiveNumberSummary::getSimpleMaximum()
{
    return simplemaximum;
}

ostream& operator<<(ostream &dout,FiveNumberSummary f) //friend function
{
    dout.precision(4);
    float a = f.getSimpleMinimum();
    float b = f.getFirstQuartile();
    float c = f.getMedian();
    float d = f.getThirdQuartile();
    float e = f.getSimpleMaximum();
    // a =  floor(a*10000)*0.0001;
    // b =  floor(b*10000)*0.0001;
    // c =  floor(c*10000)*0.0001;
    // d =  floor(d*10000)*0.0001;
    // e =  floor(e*10000)*0.0001;
    a = truncfunc(a);
    b = truncfunc(b);
    c = truncfunc(c);
    d = truncfunc(d);
    e = truncfunc(e);
    dout<<fixed<<a<<","<<b<<","<<c<<","<<d<<","<<e<<" ";

    return(dout);
}