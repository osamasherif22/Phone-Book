#include <stdio.h>
#include <stdlib.h>

// declarations of structures
typedef struct{
    int day;
    int month;
    int year;
}birth;

typedef struct {
    char first_name[256];
    char last_name[256];
    birth BD;
    char adress[128];
    char city[128];
    int mob_num;
}cont;
cont arr[256];

void LOAD ()
{
char name ;
int count =0 ;
FILE *fRptr ;
/*puts("enter your text name :");
gets(name);*/
fRptr = fopen("tes.txt","r");
if (fRptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

while(!feof(fRptr))
{
fscanf(fRptr,"%[^,],",arr[count].first_name);
fscanf(fRptr,"%s,",arr[count].last_name);
fscanf(fRptr,"%[^-]-",&arr[count].BD.day);
fscanf(fRptr,"%d-",&arr[count].BD.month);
fscanf(fRptr,"%d,",&arr[count].BD.year);
fscanf(fRptr,"%s,",arr[count].adress);
fscanf(fRptr,"%s,",arr[count].city);
fscanf(fRptr,"%d\n",&arr[count].mob_num);

count++;
}
fclose(fRptr);
char ch ;
while ((ch = getchar()) != '\n' && ch != EOF) ;
printf("\n\nPress ENTER to continue.");
while ((ch = getchar()) != '\n' && ch != EOF) ;
}


void SAVE()
{
FILE*fptr;
fptr=fopen("our_directory.txt","w");

for(int i=0;i<20;i++)
    {

fprintf(fptr,"%s,%s,%d-%d-%d,%s,%s,%d\n",arr[i].first_name,arr[i].last_name,arr[i].BD.day,arr[i].BD.month,arr[i].BD.year,arr[i].adress,arr[i].city,arr[i].mob_num);
    }
    fclose(fptr);
char ch ;
while ((ch = getchar()) != '\n' && ch != EOF) ;
printf("\n\nPress ENTER to continue.");
while ((ch = getchar()) != '\n' && ch != EOF) ;
}


void ADD(){
    int n , i=0;
    printf("How many contacts do you want to add : ");
    scanf("%d",&n);

    for(i;i<n;i++){
        printf("Enter the first name of contact No.%d:",(i+1));
       scanf("%s",arr[i].first_name);
        printf("Enter the last name of contact No.%d:",(i+1));
       scanf("%s",arr[i].last_name);
        printf("Enter the birth date of the contact No.%d:\n",(i+1));
        printf("day: ");
     scanf("%d",&arr[i].BD.day);
        printf("\nmonth: ");
       scanf("%d",&arr[i].BD.month);
        printf("year: ");
     scanf("%d",&arr[i].BD.year);
        printf("Enter the address of the contact No.%d:",(i+1));
      scanf(" %[^\t\n]s",arr[i].adress);
        printf("Enter the city of the %d th contact:",(i+1));
    scanf(" %[^\t\n]s",arr[i].city);
        printf("Enter the mobile number of the contact No.",(i+1));
  scanf("[^\t\n]%d",&arr[i].mob_num);
          printf("______________________________________________________\n");
    }
char ch ;
while ((ch = getchar()) != '\n' && ch != EOF) ;
printf("\n\nPress ENTER to continue.");
while ((ch = getchar()) != '\n' && ch != EOF) ;
}
