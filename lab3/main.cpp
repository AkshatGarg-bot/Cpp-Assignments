#include<iostream>
#include<cstdlib>
#include <iomanip>
#include<cstring>
#include<vector>
#include<bits/stdc++.h>
#include"DataSequence.h"
#include"FiveNumberSummary.h"
#include"Histogram.h" 
using namespace std;
int checker(char str[])    //checks any unwanted character in the string like @ or somthing like that
{
    int l  = strlen(str);
    for(int i=0;i<l;i++)
    {
        if((int)str[i]<32)
        {
            return 0;
        }
        else if((int)str[i]>32 && (int)str[i]<44)
        {
            return 0;
        }
        else if((int)str[i]==47)
        {
            return 0;
        }
        else if((int)str[i]>57)
        {
            if((int)str[i]==65 || (int)str[i]==78)
            {}
            else{return 0;}
            
        }
    }
    return 1;
}
int input(float *values[],int *sequence_length,int no_of_sequence,char str[])   //checks the correct string values and rerturns the number of sequencess
{
    if(checker(str)==0)
    {
        return 0;
    }
    int p =0;
    int indexing[1000];    //stores indexing for each sequence
    for(int i=0;i<1000;i++)
    {
        indexing[i]=0;
    }
    int parameter = 0;   //parameter = 1 means N phasae parameter =2 means  PHASE AND PARAMNETER =3 MEANS -1 PHASE
    int delimiter,seq_number = 0;
    int input_checker = 0;
    int length = strlen(str);
    char *value = (char*)calloc(20, sizeof(char)); 
    int index = 0;
    for(int i=length-1;i>=0;i--)         //checking whther the ast charqacter in -1 or not
    {
        if(str[i]==' ')
        {
            index = i;
            break;
        }
    }
    for(int i=index+1;i<length;i++)
    {
        value[p++] = str[i];
    }
    delimiter = atoi(value);
    if(delimiter != -1 || strlen(value)!=2)  //if -1 is there then length should be fized that is 2
    {
        return 0;
    }
    free(value);
    value = (char*)calloc(20, sizeof(char));
    index = 0;
    if(str[0]=='N' && str[1]==',')          //should start with N as there should be a place where we start the sequence
    {
        parameter = 1;
        input_checker = 1;                //check whether we are putting a sequwnce number or a seequence value
        no_of_sequence++;
    }
    else
    {
        return 0;
    }
    for(int i=2;i<length;i++)
    {
        if(input_checker == 1 && parameter==1 && str[i]==' ')          //parameter for the number n
        {    
            int l = strlen(value);
            for(int k=0;k<l;k++)           
            {
                if((int)value[k]>47 && (int)value[k]<58)  
                {

                }
                else       //all condition except this are false
                {
                    return 0;
                }
            }
            float temp = atof(value);
            int variable = temp;
            float p = temp - (float)variable;
            if(p != 0.0)       //the number should be a integer
            {
                return 0;
            } 
            if(variable == 0) //if n==0 then we do nothing and we have to take a -1 so parameter  =3
            {
                no_of_sequence--;
                parameter = 3;
                free(value); 
                value = (char*)calloc(20, sizeof(char));
                index = 0;
            }
            else
            {
                sequence_length[no_of_sequence-1] = (int)temp;
                free(value);
                value = (char*)calloc(20, sizeof(char));
                index = 0;
                input_checker = 0;
            }
            
        }   
        else if(input_checker==0 && parameter == 1 && str[i] ==',') //taking the input values in the array 
        {
            int count = 0;
            int l = strlen(value);
            for(int k=0;k<l;k++)
            {
                if((int)value[k]>47 && (int)value[k]<58)
                {

                }
                else if((int)value[k] == 46)
                {
                    count++;
                }
                else
                {
                    return 0;
                }
            }
            if(count>1)
            {
                return 0;
            }
            float temp = atof(value);
            if(temp<=0)                   
            {
                return 0;
            }
            values[no_of_sequence-1][indexing[no_of_sequence-1]++] = temp;
            free(value); 
            value = (char*)calloc(20, sizeof(char));
            index = 0;
        }
        else if(input_checker==0 && parameter == 1 && str[i] ==' ') //final element of the sequence
        {
            int count = 0;
            int l = strlen(value);
            for(int k=0;k<l;k++)
            {
                if((int)value[k]>47 && (int)value[k]<58)
                {

                }
                else if((int)value[k] == 46)
                {
                    count++;
                }
                else
                {
                    return 0;
                }
            }
            if(count>1)
            {
                return 0;
            }
            float temp = atof(value);
            if(temp<=0)                   
            {
                return 0;
            }
            values[no_of_sequence-1][indexing[no_of_sequence-1]++] = temp;
            free(value); 
            value = (char*)calloc(20, sizeof(char));
            index = 0;
            parameter = 3;
        }
        else if(parameter == 3 && str[i] == ' ')      //-1
        {
            delimiter = atoi(value);
            if(delimiter != -1 || strlen(value)!=2)
            {
                return 0;
            }
            free(value); 
            value = (char*)calloc(20, sizeof(char));
            index = 0;
            parameter = 0;
        }
        else  if (str[i]==',' && parameter == 0)
        {

            if(value[0]=='N' && strlen(value)==1)
            {
                parameter = 1;
                input_checker = 1;
                no_of_sequence++;
                free(value); 
                value = (char*)calloc(20, sizeof(char));
                index = 0;
            }
            else if(value[0]=='A' && strlen(value)==1)
            {
                parameter = 2;
                input_checker=1;
                free(value); 
                value = (char*)calloc(20, sizeof(char));
                index = 0;
            }
            else
            {
                return 0;
            }
        }
        else if(parameter==2 && str[i]==',' && input_checker==1)  //this keeps track of the value of A(sequence number assiciated with A) 
        {
            int l = strlen(value);
            for(int k=0;k<l;k++)
            {
                if((int)value[k]>47 && (int)value[k]<58)
                {}
                else 
                {
                    return 0;
                }
            }
            float temp = atof(value);
            int variable = temp;
            float p = temp - (float)variable;
            if(p != 0.0)
            {
                return 0;
            } 
            if(variable+1 > no_of_sequence  || variable<0)
            {
                return 0;
            }   
    
            seq_number = variable;
            input_checker = 0;
            free(value); 
            value = (char*)calloc(20, sizeof(char));
            index = 0;
        }
        else if(seq_number >=0 && input_checker==0 && parameter==2 && str[i]== ' ') //this checks what value has to be added
        {
            int count = 0;
            int l = strlen(value);
            for(int k=0;k<l;k++)
            {
                if((int)value[k]>47 && (int)value[k]<58)
                {

                }
                else if((int)value[k] == 46)
                {
                    count++;
                }
                else
                {
                    return 0;
                }
            }
            if(count>1)
            {
                return 0;
            }
            float temp = atof(value);
            if(temp<=0)                   
            {
                return 0;
            }
            values[seq_number][indexing[seq_number]++] = temp;
            sequence_length[seq_number]++; 
            free(value); 
            value = (char*)calloc(20, sizeof(char));
            index = 0;
            parameter = 3;
        }
        else
        {
            value[index++] = str[i];
        }
        
    }
    for(int i=0;i<no_of_sequence;i++)  //final checking
    {
        if(indexing[i] != sequence_length[i])
        {
            return 0;
        }
    }
    return no_of_sequence;
}
int main()
{
    int no_of_sequence = 0; //stores the number of sequqences it is modified in input funtion
    float *values[1000];  //2d pointer array keeps track of all the sequences
    char str[10000]; //input
    cin.getline(str,sizeof(str));
    int *sequence_length = (int*)calloc(1000, sizeof(int)); //has the sequence length correspoding to each sequence 
    for (int i=0; i<1000; i++)  //makes 2d array
    {
        values[i] = (float *)malloc(1000 * sizeof(float)); 
    }
    no_of_sequence = input(values,sequence_length,no_of_sequence,str); 
    if(no_of_sequence) //if positive that good
    {
        vector<DataSequence> DSVector; //vector
        vector<Histogram> histograms;
        for(int i=0;i<no_of_sequence;i++)
        {
            DataSequence d(values[i],sequence_length[i]); //instance of a data sequence correspoding to each class
            d.setFiveNumberData(); //setting up the five number i.e the lower quartile, min, max , third quartile, median
            Histogram h(10); //histogram instance
            d.setHistogram(h,10); //setting histogram
            histograms.push_back(h); //adding to the vector
            DSVector.push_back(d);
        }
        for(int i=0;i<no_of_sequence-1;i++) //printing process going on
        {
            cout<<DSVector.at(i);
            cout<<histograms[i];
            cout<<"-1 ";
        }
        cout<<DSVector.at(no_of_sequence-1);
        cout<<histograms[no_of_sequence-1];
        cout<<"-1";
    }
    else 
    {
        cout<<"-1";
    }
    return 0;
}
