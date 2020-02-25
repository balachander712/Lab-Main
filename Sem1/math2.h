#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int ispowtwo(int a)
{
    if( a & (a-1)==0 )
    {
        return 1;
    }
    else
    {
        return 0;
    }   
}

int iseven(int a)
{
    if(a%2==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isodd(int a)
{
    if(a%2 ! = 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isprime(int a)
{
    int f=0;
    for(int i=0; i<n/2; i++)
    {
        if( a%i=0 )
        {
            f=1;
            break;
        }
    }
    if(f==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
double areacircle(int r)
{
    double area;
    area=3.14159*r*r;
    return area;
}
