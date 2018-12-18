#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>

/** Declarations of Structures **/

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

/**Global Variable**/

cont arr[256];
int counter=0;


/******************************************* SORT FUNCTION *******************************************/

void bubble_sort()
{
for (int i=0 ; i<counter-1 ; i++)
{
    for (int j=0 ; j<counter-i-1;j++)
    {
        if((strcmp(arr[j].last_name,arr[j+1].last_name)>0))
        {
            cont temp ;
            temp = arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
}

/******************************************** LOAD FUNCTION *******************************************/
void LOAD ()
{
char filename[256] ;
FILE *fRptr ;
puts("enter your text name :");
scanf("%s",filename);
fRptr = fopen(filename,"r");
if (fRptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
int count=counter ;
while(!feof(fRptr))
{
fscanf(fRptr,"%[^,],%s,%[^-]-%d-%d,%s,%s,%d\n",arr[count].first_name,arr[count].last_name,&arr[count].BD.day,&arr[count].BD.month,&arr[count].BD.year,arr[count].adress,arr[count].city,&arr[count].mob_num);
/*fscanf(fRptr,"%s,",arr[count].last_name);
fscanf(fRptr,"%[^-]-",&arr[count].BD.day);
fscanf(fRptr,"%d-",&arr[count].BD.month);
fscanf(fRptr,"%d,",&arr[count].BD.year);
fscanf(fRptr,"%s,",arr[count].adress);
fscanf(fRptr,"%s,",arr[count].city);
fscanf(fRptr,"%d\n",&arr[count].mob_num);*/

count++;
}
fclose(fRptr);
printf("Uploaded successfully");
char ch ;
while ((ch = getchar()) != '\n' && ch != EOF) ;
printf("\n\nPress ENTER to continue.");
while ((ch = getchar()) != '\n' && ch != EOF) ;
}

/******************************************* SAVE FUNCTION *******************************************/

void SAVE()
{
FILE*fptr;
fptr=fopen("our_directory.txt","w");
printf("%d",counter);
for(int i=0;i<counter;i++)
    {
fprintf(fptr,"%s,%s,%d-%d-%d,%s,%s,%d\n",arr[i].first_name,arr[i].last_name,arr[i].BD.day,arr[i].BD.month,arr[i].BD.year,
        arr[i].adress,arr[i].city,arr[i].mob_num);
//fprintf(fptr,"\n");
    }
    fclose(fptr);
    printf("Saved successfully");
char ch ;
while ((ch = getchar()) != '\n' && ch != EOF) ;
printf("\n\nPress ENTER to continue.");
while ((ch = getchar()) != '\n' && ch != EOF) ;
}


/******************************************* ADD FUNCTION *******************************************/

void ADD(){

   // void clrscr();
    int n ;
    printf("\n\nHow many contacts do you want to add : ");
    scanf("%d",&n);

    for(int i=0 ;i<n;i++,counter++){
        printf("\nEnter the first name of contact No.%d:",(i+1));
       scanf("%s",arr[counter].first_name);
        printf("Enter the last name of contact No.%d:",(i+1));
       scanf("%s",arr[counter].last_name);
        printf("Enter the birth date of the contact No.%d:\n",(i+1));
        printf("day: ");
     scanf("%d",&arr[counter].BD.day);
        printf("month: ");
       scanf("%d",&arr[counter].BD.month);
        printf("year: ");
     scanf("%d",&arr[counter].BD.year);
        printf("Enter the address of the contact No.%d:",(i+1));
      scanf(" %[^\t\n]s",arr[counter].adress);
        printf("Enter the city of the %d th contact:",(i+1));
    scanf(" %[^\t\n]s",arr[counter].city);
        printf("Enter the mobile number of the contact No.",(i+1));
  scanf("%d",&arr[counter].mob_num);
          printf("\n\n\n______________________________________________________\n");

    }

char ch ;
while ((ch = getchar()) != '\n' && ch != EOF) ;
printf("\n\nPress ENTER to continue.");
while ((ch = getchar()) != '\n' && ch != EOF) ;
}




/***************************************** PRINT FUNCTION *******************************************/
void PRINT()
{

// sorted fun
bubble_sort();
printf("\n\nPrinting entire Directory In sorted Order \n\n");
for (int i=0 ;i<counter;i++)
{
  printf("first name is : %s \n",arr[i].first_name);
  printf("last name is :%s  \n",arr[i].last_name);
  printf("address is : %s\n",arr[i].adress);
  printf("city is :%s  \n",arr[i].city);
  //printf("birth day is : \n",arr[i].first_name);
  printf("mobile number is : %d \n",arr[i].mob_num);


}
printf(" \n\n End of Printing \n\n");



char ch ;
while ((ch = getchar()) != '\n' && ch != EOF) ;
printf("\n\nPress ENTER to continue.");
while ((ch = getchar()) != '\n' && ch != EOF) ;

}
/******************************************* SEARCH FUNCTION *******************************************/
void SEARCH()
{
    bubble_sort();
    char target[128] ;
    puts("\nEnter last name you want to search with : ");
   scanf("%s",target);
    for ( int i =0; i < counter; i++)
    {
        if ((strcmp(target,arr[i].last_name)==0))
        {
printf("%s  %s  %s  %s  %d \n ",arr[i].first_name,arr[i].last_name,arr[i].adress,arr[i].city,arr[i].mob_num);
        }
    }

char ch ;
while ((ch = getchar()) != '\n' && ch != EOF) ;
printf("\n\nPress ENTER to continue.");
while ((ch = getchar()) != '\n' && ch != EOF) ;

}

/******************************************* MODIFY FUNCTION *******************************************/


void MODIFY ()
{

/** searching for this contact and return his index in structure **/
 int* index =(int*)malloc(100);
    char target[128] ;
    puts("\nEnter last name you want to search with : ");
   scanf("%s",target);
   int j=0 ;
    for ( int i =0; i < counter; i++)
    {
        if ((strcmp(target,arr[i].last_name)==0))
        {
            index[j]=i; j++;
printf("no.%d to have this last name : %s %s %s %s %d \n ",j,arr[i].first_name,arr[i].last_name,arr[i].adress,arr[i].city,arr[i].mob_num);
        }
    }
    int n ;
printf("what of them you want to modify in : ");
scanf("%d",&n);
int temp,m ;
for (m=0;m<5;m++)
{
    if(n==m) temp=index[m];
}
cont* p=arr+(index[m]-1);
int choice1;
do
{	printf("\n*** Enter what to modify ***\n\n");
    printf( "1:Last name\n2:First name\n3:Address\n4:City\n5:Mobile number\n6:Nothing to modify\n" );
    scanf("%d",&choice1);

		switch(choice1)
		{
			case 1 : printf("enter new last name :");
                     gets(p->last_name);
		    case 2 : printf("enter new first name :");
                     gets(p->first_name); ;
            case 3 : printf("enter new address :");
                     gets(arr[index[m]].city);
            case 4 : printf("enter new city :");
                     gets(arr[index[m]].city);
            case 5 : printf("enter new mobile number :");
                     scanf("%d",&p->mob_num);
            case 6 :
                printf("\nyou are quiting !\n");
				return(0);
			default: printf("\nInvalid choice!\n");
				break;
		}
	 } while (choice1 != 7);

char ch ;
while ((ch = getchar()) != '\n' && ch != EOF) ;
printf("\n\nPress ENTER to continue.");
while ((ch = getchar()) != '\n' && ch != EOF) ;

}

