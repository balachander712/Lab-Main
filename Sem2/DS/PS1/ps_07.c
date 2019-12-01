#include <stdio.h>

void main()
{
    int i,j,vote[5][4];
    int total=0;
    int cvote[4];
    float percent,max=0;
    int win;
    for(i=0;i<4;i++)
    {
        printf("Enter the votes of the candidates in order ");
        for(j=0;j<5;j++)
            scanf("%d",&vote[i][j]);
    }
     for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
        {
            cvote[i]+=vote[j][i];
            total+=vote[j][i];
        }
        printf("Total number of votes by candidate %c is %.2d\n",i+65,cvote[i]);
    }
    for(i=0;i<4;i++)
    {
        percent=(float)(cvote[i]*100)/total;
        printf("The percentage of votes recieved by candidate %c is %f%%\n",i+65,percent);
        if(percent>max)
        {
            max=percent;
            win=i;
        }
    }
    printf("The winner is candidate %c\n",win+65);
}
