#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>


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
/* Function to find the inverse of a matrix*/

/*Function to get the Cofactor matrix*/
void getCofactor(int A[3][3], int temp[3][3], int p,
                 int q, int n)
    {
        int i=0, j=0;

       for(int row =0; row<n; row++)
       {
           for(int col=0; col<n; col++)
           {
               if(row!=p && col!=q)
               {
                   /*Elements not in given row or coloumn are copied
                   to a temporary matrix*/
                   temp[i][j++]= A[row][col];

                    /*Increase the row index and reset the col index*/
                    if(j== n-1)
                    {
                        j=0;
                        i++;
                    }
               }
           }
       }

    }

    /*To find the determinant of a 3x3 matrix*/
    int determinant(int A[3][3],int n)
    {
        int D=0;

        if(n==1)
            return A[0][0];

        int temp[3][3];

        /*Sign multiplier*/
        int sign= 1;

        for(int k=0; k<n; k++)
        {
            /*Calling cofactor function to get the cofactor*/
            getCofactor(A,temp,0,k,n);
            D += sign*A[0][k]*determinant(temp, n-1);

            /*Alternate the terms with opposite signs*/
            sign=-sign;

        }

        return D;
    }
/*To get the adjoint matrix*/

void adjoint(int A[3][3],int adj[3][3])
{
    int sign=1, temp[3][3];

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            /*To get cofactor of A[i][j]*/
            getCofactor(A, temp, i, j, 3);

            /*Sign of adj[i][j] is positive if row and col index
            are even*/
            sign = ((i+j)%2==0)? 1: -1;

            /*Interchanging row and cols to get the transpose
            of cofactor matrix*/
            adj[j][i] = (sign)*(determinant(temp, 2));
        }
    }
}

/*A boolean function to find the inverse*/

bool inverse(int A[3][3], float inverse[3][3])
{
    int det=determinant(A,3);

    /*Returns false if matrix is singular*/
    if(det==0)
    {
        printf("Singular Matrix!!!! Cannot find inverse>>>>!!!");
        return false;
    }

    int adj[3][3];
    adjoint(A,adj);

    for(int i=0; i<3;i++)
    {
        for(int j=0; j<3;j++)
        inverse[i][j]=adj[i][j]/(float)det; /*Storing the inverse matrix*/
    }
    return true;
}

/*int main()
{
    int A[3][3] = { {6, 5, 7},
                    {5, 4, 8},
                    {-3, 1, 5}
                    };


    int adj[3][3];  // To store adjoint of A[][]

    float inv[3][3]; // To store inverse of A[][]



    printf( "\nThe Inverse is :\n");
    if (inverse(A, inv))
        {
            for(int i=0;i<3 ;i++)
            {
                for(int j=0;j<3;j++)
                {
                    printf("%.2f ",int[i][j]);
                }
                printf("\n");
            }
        }

    return 0;
}*/

void multiply(int a[3][3], int b[3][3])
{

    int mul[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
                mul[i][j] += a[i][k]*b[k][j];
        }
    }


    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            a[i][j] = mul[i][j];
}


int power(int F[3][3], int n)
{
    int M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};


    if (n==1)
        return F[0][0] + F[0][1];

    power(F, n/2);

    multiply(F, F);

    if (n%2 != 0)
        multiply(F, M);


    return F[0][0] + F[0][1] ;
}


int findNthTerm(int n)
{
    int F[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}} ;

    return power(F, n-2);
}

/*int main()
{
   int n = 5;

   printf("F(5) is %d " , findNthTerm(n));

   return 0;
}*/

void decToBinary(int n)
{
    int binary[32];

    int i=0;
    while(n>0)
    {
        binary[i]=n%2;
        n=n/2;
        i++;
    }

    for(int j=i-1;j>=0;j--)
        printf("%d",binary[j]);
}

/*int main()
{
    int n = 17;
    decToBinary(n);
    return 0;
}*/
int binaryToDecimal(int n)
{
    int num=n;
    int dec=0;

    int base=1;
    int temp=num;

    while(temp)
    {
        int last= temp%10;

        temp=temp/10;
        dec+= last*base;

        base=base*2;
    }

    return dec;
}

/*int main()
{
    int num = 10101001;

    printf("%d",binaryToDecimal(num));
}*/

int Multiply(int x, int res[], int res_size);


void factorial(int n)
{
    int res[500];


    res[0] = 1;
    int res_size = 1;


    for (int x=2; x<=n; x++)
        res_size = Multiply(x, res, res_size);


    for (int i=res_size-1; i>=0; i--)
        printf("%d",res[i]);
}


int Multiply(int x, int res[], int res_size)
{
    int carry = 0;

    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;


        res[i] = prod % 10;


        carry  = prod/10;
    }


    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

/*
int main()
{
    factorial(100);
    return 0;
}*/

