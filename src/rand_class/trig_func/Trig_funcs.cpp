
    // setup the class with accuracy parameters ie = 10 meaning 10 iterations
    // then supply whether the value gonna be degrees or radians
    // if degree pass d else anything will result in radians calculation.

//for sine
        //s = s + powerof1(i) * mypower(x, 2 * i + 1) / fact(2 * i + 1); //taylors series

// for cosine
        //s = s + powerof1(i) * mypower(x, 2 * i) / fact(2 * i);


#include "trig.h"
#include<stdlib.h>

trignometry::trignometry(int iterations, char choice)
    {
        pof1 = 1;
        iter = iterations;
        c = choice;
        s = 0;
        PI = (float)PI_doub;
        sign = 1.0;
        p=1;
    } 

// my power functions cannot handle fractional power exp, its a basic slow power func
float trignometry::mypower(float base, int exp)
{
    if(exp==0)
        return 1;     
    p = mypower(base,exp/2);
    if(exp%2==0)
        return p*p;
    else
        return base*p*p;
}

void trignometry::rad2rad(float *rad)
{
    while(*rad>2*PI)
        *rad = *rad - 2*PI;
}

void trignometry::deg2rad(float *deg)
{
    while(*deg>360)
        *deg = *deg - 360;

    *deg = *deg * PI/180;    
    rad2rad(deg);
}

float trignometry::sin(float x)
{  
    pof1 = 1;
    s = 0.0;
    if(x<0)
    {
        sign = -1.0;
        x = x * -1;
    }
        
    if(c=='r')
        rad2rad(&x);
    else if(c=='d')
        deg2rad(&x);
    else
        exit(EXIT_FAILURE);

    
    for (int i = 0; i < iter; i++)
    {
        if ((i & 1) == 1)
            pof1 = -1;
        else
            pof1 = 1;

        s = s + pof1 * mypower(x, 2 * i + 1) * (float)invf[2 * i + 1]; //taylors series
    }

    return s*sign;
    sign = 1.0;
}

float trignometry::cos(float x)
{
    pof1 = 1;
    s = 0.0; 
    if(x<0)
        x = x * -1;
    if(c=='r')
        rad2rad(&x);
    else if(c=='d')
        deg2rad(&x);
    else
        exit(EXIT_FAILURE);

    for (int i = 0; i < iter; i++)
    {
        if ((i & 1) == 1)
            pof1 = -1;
        else
            pof1 = 1;
        s = s + pof1 * mypower(x, 2 * i) * (float)invf[2 * i];
    }

    return s;
}