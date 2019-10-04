#include <stdio.h>

int main()
{
    int price[5];
    price[1]= 5000;
    price[2]=10000;
    price[3]=2000;
    price[4]=8000;

    int q[5];
    int i,j;

    printf("Enter the quantity of MP3 Player sold ");
    scanf("%d",&q[1]);

    printf("Enter the quantity of WII sold ");
    scanf("%d",&q[2]);

    printf("Enter the quantity of DVD Player sold ");
    scanf("%d",&q[3]);

    printf("Enter the quantity of Digital Camera sold ");
    scanf("%d",&q[4]);

    printf("Product Unit\t\tPrice\tQty\tTotal Price ");

    printf("MP3 player\t\t%d\t%d\t%d\n",price[1],q[1],price[1]*q[1]);
    printf("WII\t\t%d\t%d\t%d\n",price[2],q[2],price[2]*q[2]);
    printf("DVD Player\t\t%d\t%d\t%d\n",price[3],q[3],price[3]*q[3]);
    printf("Digital Camera\t\t%d\t%d\t%d\n",price[4],q[4],price[4]*q[4]);

    int total= (price[1]*q[1]) + (price[2]*q[2]) + (price[3]*q[3]) + (price[4]*q[4]);

    printf("Total\t%d\n",total);

    int max=q[1];

    for(i=1;i<=4;i++)
    {
        if(max<q[i])
            max=q[i];
    }

    for(i=0;i<=4;i++)
    {
        if(max==q[i])
            break;
    }

    int min=q[i];

    for(j=1;j<=4;j++)
    {
        if(min>q[j])
            min=q[j];
    }

    for(j=1;j<=4;j++)
    {
        if(min==q[j])
            break;
    }

    if(i==1)
        printf("Product most sold: MP3 Player %d\n",i);
    else if(i==2)
        printf("Product most sold :WII %d\n",i);
    else if(i==3)
        printf("Product most sold :DVD player %d\n",i);
    else if(i==4)
        printf("Product most sold :Digital camera %d\n",i);

    if(j==1)
        printf("Product least sold : MP3 Player %d\n",j);
    else if(j==2)
            printf("Product least sold : WII %d\n",j);
    else if(j==3)
            printf("Product least sold : WII %d\n",j);
    else if(j==4)
            printf("Product least sold : Digital Camera %d\n",j);

}
