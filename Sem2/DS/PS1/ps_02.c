#include<stdio.h>
void main()
{
        int n,i;
        printf("Enter the number of data inputs: ");
        scanf("%d",&n);
        int a[n];
        printf("Enter the temperatures:\n");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        int hd=0,pd=0,cd=0;
        for(i=0;i<n;i++)
        {
                if(a[i]>=85)
                        hd++;
                else if(a[i]>=60&&a[i]<85)
                        pd++;
                else if(a[i]<60)
                        cd++;
        }
        printf("The number of hot days are %d\n",hd);
        printf("The number of pleasent days are %d\n",pd);
        printf("The number of cold days are %d\n",cd);
}
