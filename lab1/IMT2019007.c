//program
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
float truncfunc(float x) { return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4  ;  }
float Manhattandistance(float v1[],float v2[],int n)   //manhattan distance
{
    float distance = 0.0;
    for(int i=0;i<n;i++)
    {
        distance += fabs(v1[i]-v2[i]);
    }
    return distance;
}
float Euclideandistance(float v1[],float v2[],int n)  //euclidean distance
{
    float distance = 0.0;
    for(int i=0;i<n;i++)
    {
        distance += pow((v1[i]-v2[i]),2);
    }
    distance = sqrt(distance);
    return distance;
}
float Chebyshevdistance(float v1[],float v2[],int n) //chebyshev distance
{
     float distance = 0.0;
    for(int i=0;i<n;i++)
    {
        if(distance< fabs(v1[i]-v2[i]))
        {
            distance = fabs(v1[i]-v2[i]);
        }
    }
    return distance;
}
float KLdiv(float v1[],float v2[],int n)   //KL DIVERGENCE
{
    float distance = 0.0;
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
float KL(float v1[],float v2[],int n)    //KL VALUE
{
    float distance = 0.0;
    for(int i=0;i<n;i++)
    {
        distance += (v1[i])*(log(v1[i]/v2[i]));
    }
    return distance;
}
float JSdistance(float v1[],float v2[],int n)   //JS DISTANCE
{
    float distance=0.0;
    float mid[n];
    for(int i=0;i<n;i++)
    {
        mid[i]=(v1[i]+v2[i])/2;
    }
    float p1 = KL(v1,mid,n);
    float p2 = KL(v2,mid,n);
    distance += (p1+p2)/2;
    distance = sqrt(distance);
    return distance;
}
int main()
{
    int n;
    scanf("%d",&n);       
    int parameter = 0;
    if(n<1)                   //condition of n
    {
        parameter = 1;
    }
    if(parameter == 1)
    {
        printf("-1");
        return 0;
    }
    char c;
    char limiter[5];
    fgets(limiter, 5, stdin);
    if((int)limiter[3]!=32)
    {
        printf("-1");
        return 0;        
    }
    if((int)limiter[0] != 32)
    {
        printf("-1");
        return 0;
    }
    if (limiter[1] != '-' || limiter[2] != '1')// if it is not equal to -1. then print "-1".
    {
        printf("-1");
        return 0;
    }
    float v1[n],v2[n];
    char str[100];
    for(int i=0;i<n-1;i++)
    {
        scanf("%f%c",&v1[i],&c);
        if((int)c != 44 || v1[i]<=0.0)      //commma should be there after each float value and the value should not be greater than 0
        {
            printf("-1");
            return 0;
        }
        if(c=='\n')                           //less number of inputs
        {

	    printf("-1");
            return 0;
	    }
    }
    scanf("%f",&v1[n-1]);       //scanning n-1th index
    if(v1[n-1]<=0)              //checking the value +ve or -ve
    {
        printf("-1");
        return 0;
    }
    char lim[5];
    fgets(lim, 5, stdin);
    if((int)lim[3]!=32)  //user should not give any additional characters here
    {
        printf("-1");
        return 0;
    }
    if((int)lim[0] != 32)  //user should not give any additional characters here
    {
        printf("-1");
        return 0;
    }
    if (lim[1] != '-' || lim[2] != '1')// if it is not equal to -1. then print "-1".
    {
        printf("-1");
        return 0;
    }
    char c1;
    for(int i=0;i<n-1;i++)
    {
        scanf("%f%c",&v2[i],&c1);
        if((int)c1 != 44 || v2[i]<0.0)
        {
            printf("-1");
            return 0;
        }
        
        if(c=='\n')
        {
	    printf("-1");
            return 0;
	}
    }
    scanf("%f",&v2[n-1]);
    if(v2[n-1]<=0)
    {
        printf("-1");
        return 0;
    }
    fgets(str,100,stdin);   //taking -1 in the form of string
    if((int)str[2] != 49 || (int)str[1] != 45 || (int)str[0]!=32 || ((int)str[3]!=0 && (int)str[3]!=10))   //checking -1 is there or not also if we run on terminal the str[3] will be equal to 10 on domjudge it will 0
    {
        printf("-1");
        return 0;
    } 
    float sum1=0.0,sum2=0.0;
    for(int i=0;i<n;i++)   
    {
        sum1 += v1[i];
        sum2 += v2[i];
    }
    for(int i=0;i<n;i++)   //normalization of vectors
    {
        v1[i] = v1[i]/sum1;
        v2[i] = v2[i]/sum2; 
    }
    float a = Manhattandistance(v1,v2,n);
    float b = Euclideandistance(v1,v2,n);
    float cd = Chebyshevdistance(v1,v2,n);
    float d = KLdiv(v1,v2,n);
    float e = JSdistance(v1,v2,n);
    a = truncfunc(a);
    b = truncfunc(b);
    cd = truncfunc(cd);
    d = truncfunc(d);
    e = truncfunc(e);  
    printf("%.4f,",a);
    printf("%.4f,",b);
    printf("%.4f,",cd);
    printf("%.4f,",d);
    printf("%.4f",e);
    return 0;
}

