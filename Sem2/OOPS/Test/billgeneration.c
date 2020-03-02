#include <stdio.h>
#include <time.h>
#include <string.h>

struct items
{
    char item_name[20];
    int unit_price;
};

void main()
{
    struct items list[20];

    strcpy(list[1].item_name,"Pencil");
    list[1].unit_price=5;

    strcpy(list[2].item_name,"Scale");
    list[2].unit_price=5;

    strcpy(list[3].item_name,"Eraser");
    list[3].unit_price=4;

    strcpy(list[4].item_name,"Marker");
    list[4].unit_price=20;

    strcpy(list[5].item_name,"NoteBook 80p");
    list[5].unit_price=20;

    strcpy(list[6].item_name,"NoteBook 150p");
    list[6].unit_price=30;

    strcpy(list[7].item_name,"NoteBook 200p");
    list[7].unit_price=40;

    strcpy(list[8].item_name,"Whitener");
    list[8].unit_price=25;

    strcpy(list[9].item_name,"Stapler");
    list[9].unit_price=50;

    strcpy(list[10].item_name,"Chocolate");
    list[10].unit_price=15;


    strcpy(list[11].item_name,"Pen");
    list[11].unit_price=10;

    printf("\t\tWELCOME TO THE STORE\n\n\n");

    FILE *fp=fopen("bill.txt","w+");
    int n,q;
    int total=0;
    int i=1;

    do
    {
        printf("Enter 1 for pencil\n");
        printf("Enter 2 for Scale\n");
        printf("Enter 3 for Eraser\n");
        printf("Enter 4 for Marker\n");
        printf("Enter 5 for NoteBook 80p\n");
        printf("Enter 6 for NoteBook 150p\n");
        printf("Enter 7 for NoteBook 200p\n");
        printf("Enter 8 for Whitener\n");
        printf("Enter 9 for Stapler\n");
        printf("Enter 10 for Chocolate\n");
        printf("Enter 11 for Pen\n");
        printf("Enter 0 to exit\n");
        scanf("%d",&n);
        if(n==0)
            break;
        printf("Enter the number of units ");
        scanf("%d",&q);


            fprintf(fp,"%d.  %s---------------%d--\n",i,list[n].item_name,q);
            total+=list[n].unit_price;

            i++;

            fprintf(fp,"\n\n\t\tTOTAL\t\t\t%d",total);

            time_t curtime;
            time(&curtime);
            fprintf(fp,"%s",ctime(&curtime));

    }while(1);
}


