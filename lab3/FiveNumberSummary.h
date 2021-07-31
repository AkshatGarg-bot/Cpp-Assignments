#ifndef FIVENUMBERSUMMARY
#define FIVENUMBERSUMMARY
using namespace std;

class FiveNumberSummary{
    private:
    float simpleminimum;
    float lowerquartile;
    float median;
    float thirdquartile;
    float simplemaximum;
    public:
    FiveNumberSummary(float v1,float v2,float v3,float v4, float v5);
    FiveNumberSummary();
    ~FiveNumberSummary()
    {
    }
    FiveNumberSummary(const FiveNumberSummary &f);
    void setSimpleMinimum(float val);
    void setLowerQuartile(float val);
    void setMedian(float val);
    void setThirdQuartile(float val);
    void setSimpleMaximum(float val);
    float getSimpleMinimum();
    float getFirstQuartile();
    float getMedian();
    float getThirdQuartile();
    float getSimpleMaximum();
    friend ostream& operator<<(ostream&,FiveNumberSummary);
    friend inline float truncfunc(float x);
};
#endif