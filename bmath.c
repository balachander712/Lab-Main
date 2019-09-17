#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd (b,a % b);
}

int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
}

/*To Determine the determinant of a matrix*/

double determinantOfMatrix(double mat[3][3])
{
    double ans;
    ans=mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2]) 
          - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) 
          + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
    
    return ans;
}

/*Function to detemine the solution for system of linear equations*/
/*Using Cramers Rule*/

void findSolution(double coeff[3][4])
{
    /*Storing Coefficient Matrices*/
    
    double d[3][3]={
        { coeff[0][0], coeff[0][1], coeff[0][2] }, 
        { coeff[1][0], coeff[1][1], coeff[1][2] }, 
        { coeff[2][0], coeff[2][1], coeff[2][2] },
    };
        
    double d1[3][3]={ 
        { coeff[0][3], coeff[0][1], coeff[0][2] }, 
        { coeff[1][3], coeff[1][1], coeff[1][2] }, 
        { coeff[2][3], coeff[2][1], coeff[2][2] },
    };
    
    double d2[3][3]={
        { coeff[0][3], coeff[0][1], coeff[0][2] }, 
        { coeff[1][3], coeff[1][1], coeff[1][2] }, 
        { coeff[2][3], coeff[2][1], coeff[2][2] },
    };
    
    double d3[3][3]={
         { coeff[0][0], coeff[0][1], coeff[0][3] }, 
        { coeff[1][0], coeff[1][1], coeff[1][3] }, 
        { coeff[2][0], coeff[2][1], coeff[2][3] },
    };
    

    
    double D=  determinantOfMatrix(d);
    double D1= determinantOfMatrix(d1);
    double D2= determinantOfMatrix(d2);
    double D3= determinantOfMatrix(d3);

    printf("D is : %lf \n", D); 
    printf("D1 is : %lf \n", D1); 
    printf("D2 is : %lf \n", D2); 
    printf("D3 is : %lf \n", D3);

    /*Case 1*/
    /*System of Equatons have unique Solutions*/
    if( D!= 0)
    {
        /*Solution for linear equations using Cramers Rule*/
        double x= D1/D;
        double y= D2/D;
        double z= D3/D;
        
        printf("Value of x is : %lf\n", x); 
        printf("Value of y is : %lf\n", y); 
        printf("Value of z is : %lf\n", z); 
    }
    
    /*Case 2*/
    else 
    {
        if(D1==0 && D2==0 && D3==0)
            printf("Infinite Solutions \n");
        else if(D1 !=0 || D2 !=0 || D3 !=0 )
            printf("No Solutions ");
    }
}
