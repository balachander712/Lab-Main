#include <stdio.h>

int power(int x, int y)
{
    if(y!=0)
        return x*power(x,y-1);
    else
        return 1;
}

int main()
{
    int x,y;

    printf("Enter the values of x and y respectively ");
    scanf("%d%d",&x,&y);

    printf("%d",power(x,y));
}
