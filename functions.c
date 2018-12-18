#include <stdio.h> #include <stdlib.h>  #include <string.h> #include <conio.h>

/** Declarations of Structures **/

typedef struct{
    int day;
    int month;
    int year;
}birth;
typedef struct {
    char first_name[100];
    char last_name[100];
    birth BD;
    char adress[100];
    char email[100];
    int mob_num;
}cont;


/**Global Variable**/
cont arr[100];
int counter=0;
                                        /***** Menu Functions ****/


/******************************************* (1) ADD FUNCTION *******************************************/

void ADD(){

    system("cls");
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
        printf("Enter the email of the %d th contact:",(i+1));
    scanf(" %[^\t\n]s",arr[counter].email);
        printf("Enter the mobile number of the contact No.",(i+1));
  scanf("%d",&arr[counter].mob_num);
          printf("\n\n\n______________________________________________________\n");

    }

char ch ;
while ((ch = getchar()) != '\n' && ch != EOF) ;
printf("\n\nPress ENTER to continue.");
while ((ch = getchar()) != '\n' && ch != EOF) ;
}

/******************************************** (2)LOAD FUNCTION *******************************************/
void LOAD ()
{
system("cls");
FILE *fRptr ;
fRptr = fopen("tt.txt","r");
if (fRptr == NULL)
    {
        printf("\nCannot open file ! \n");
    }
else {
int count=counter ;
while(!feof(fRptr))
{
fscanf(fRptr,"%[^,],%s,-%d-%d,%s,%s,%d\n",arr[count].first_name,arr[count].last_name,&arr[count].BD.day,&arr[count].BD.month,&arr[count].BD.year,arr[count].adress,arr[count].email,&arr[count].mob_num);
/*fscanf(fRptr,"%[^,],",arr[count].last_name);
fscanf(fRptr,"%[^,],",arr[count].last_name);
fscanf(fRptr,"%d-",&arr[count].BD.day);
fscanf(fRptr,"%d-",&arr[count].BD.month);
fscanf(fRptr,"%d,",&arr[count].BD.year);
fscanf(fRptr,"%[^\n,],",arr[count].adress);
fscanf(fRptr,"%[^,],",arr[count].email);
fscanf(fRptr,"%d\n",&arr[count].mob_num);*/

count++;
}
fclose(fRptr);
printf("\nUploaded successfully");
}
char ch ;
while ((ch = getchar()) != '\n' && ch != EOF) ;
printf("\n\nPress ENTER to continue.");
while ((ch = getchar()) != '\n' && ch != EOF) ;
}

/******************************************* (3)MODIFY FUNCTION *******************************************/


void MODIFY ()
{
system("cls");
 bubble_sort();
    char target[128] ;
    puts("\nEnter last name of the contact you want to Modify in : ");
   scanf("%s",target);
   int j=1;
    for ( int i =0; i < counter; i++)
    {
        if ((strcmp(target,arr[i].last_name)==0))
        {
            printf("\nContacts with this last name [%s] : \n ",target);
  printf("contact number.%d\n",i);
  printf("first name is : %s \n",arr[i].first_name);
  printf("last name is :%s \n",arr[i].last_name);
  printf("Date of birth is %d-%d-%d \n",arr[i].BD.day,arr[i].BD.month,arr[i].BD.year);
  printf("address is : %s\n",arr[i].adress);
  printf("email is :%s \n",arr[i].email);
  printf("mobile number is : %d\n",arr[i].mob_num);
  printf("\n"); j++;
        }
    }
    int k;
    printf("what is contact number does you want to Modify in :");
    scanf("%d",&k);
cont* p=&arr[k];
int choice1;
do
{	printf("\n*** Enter what to modify ***\n\n");
    printf( "1:Last name\n2:First name\n3:Address\n4:email\n5:Mobile number\n6:Nothing to modify\n" );
    scanf("%d",&choice1);

		switch(choice1)
		{
			case 1 : printf("enter new last name :");
                     gets(p->last_name);
		    case 2 : printf("enter new first name :");
                     gets(p->first_name); ;
            case 3 : printf("enter new address :");
                     gets(p->adress);
            case 4 : printf("enter new email :");
                     gets(p->email);
            case 5 : printf("enter new mobile number :");
                     scanf("%d",&p->mob_num);
            case 6 :

                printf("\nyou are quiting !\n");
				return(0);
			default: printf("\nInvalid choice!\n");
				break;
		}
	 } while (choice1 != 6);

char ch ;
while ((ch = getchar()) != '\n' && ch != EOF) ;
printf("\n\nPress ENTER to continue.");
while ((ch = getchar()) != '\n' && ch != EOF) ;

}


/******************************************* (4) DELETE *******************************************/

void DELETE()
{
system("cls");
    bubble_sort();
    char target[128] ;
    puts("\nEnter last name of the contact you want to delete : ");
   scanf("%s",target);
   int j=1;
    for ( int i =0; i < counter; i++)
    {
        if ((strcmp(target,arr[i].last_name)==0))
        {
            printf("\nContacts with this last name [%s] : \n ",target);
  printf("contact number.%d\n",i);
  printf("first name is : %s \n",arr[i].first_name);
  printf("last name is :%s \n",arr[i].last_name);
  printf("Date of birth is %d-%d-%d \n",arr[i].BD.day,arr[i].BD.month,arr[i].BD.year);
  printf("address is : %s\n",arr[i].adress);
  printf("email is :%s \n",arr[i].email);
  printf("mobile number is : %d\n",arr[i].mob_num);
  printf("\n"); j++;
        }
    }
    int k;
    printf("what is contact number does you want to delete :");
    scanf("%d",&k);
for(k;k<counter-1;k++){
    arr[k]=arr[k+1];
}
counter=counter-1;
printf("\n\nDeleted successfully !\n");

char ch ;
while ((ch = getchar()) != '\n' && ch != EOF) ;
printf("\n\nPress ENTER to continue.");
while ((ch = getchar()) != '\n' && ch != EOF) ;
}

/*****************************************(5) PRINT FUNCTION *******************************************/
void PRINT()
{
system("cls");
// sorted fun
bubble_sort();
printf("\n\nPrinting entire Directory In sorted Order \n\n");
for (int i=0 ;i<counter;i++)
{

  printf("No.%d\n",i+1);
  printf("first name is : %s \n",arr[i].first_name);
  printf("last name is :%s \n",arr[i].last_name);
  printf("Date of birth is :%d-%d-%d \n",arr[i].BD.day,arr[i].BD.month,arr[i].BD.year);
  printf("address is : %s\n",arr[i].adress);
  printf("email is :%s \n",arr[i].email);
  printf("mobile number is : %d \n",arr[i].mob_num);
  printf("\n");


}
printf(" \n\n End of Printing \n\n");



char ch ;
while ((ch = getchar()) != '\n' && ch != EOF) ;
printf("\n\nPress ENTER to continue.");
while ((ch = getchar()) != '\n' && ch != EOF) ;

}
/******************************************* (6)SEARCH FUNCTION *******************************************/
void SEARCH()
{
    system("cls");
    bubble_sort();
    char target[128] ;
    puts("\nEnter last name you want to search with : ");
   scanf("%s",target);
   int j=1;
    for ( int i =0; i < counter; i++)
    {
        if ((strcmp(target,arr[i].last_name)==0))
        {
            printf("\nContacts with this last name [%s] : \n ",target);
    printf("No.%d\n",j);
  printf("first name is : %s \n",arr[i].first_name);
  printf("last name is :%s \n",arr[i].last_name);
  printf("Date of birth is %d-%d-%d \n",arr[i].BD.day,arr[i].BD.month,arr[i].BD.year);
  printf("address is : %s\n",arr[i].adress);
  printf("email is :%s \n",arr[i].email);
  printf("mobile number is : %d\n",arr[i].mob_num);
  printf("\n"); j++;
        }
    }

char ch ;
while ((ch = getchar()) != '\n' && ch != EOF) ;
printf("\n\nPress ENTER to continue.");
while ((ch = getchar()) != '\n' && ch != EOF) ;

}



/******************************************* (7)SAVE FUNCTION *******************************************/

void SAVE()
{
    system("cls");
FILE*fptr;
fptr=fopen("directory.txt","a");
printf("%d",counter);
for(int i=0;i<counter;i++)
    {
fprintf(fptr,"%s,%s,%d-%d-%d,%s,%s,%d\n",arr[i].first_name,arr[i].last_name,arr[i].BD.day,arr[i].BD.month,arr[i].BD.year,
        arr[i].adress,arr[i].email,arr[i].mob_num);
//fprintf(fptr,"\n");
    }
    fclose(fptr);
        system("cls");
    printf("\n\nSaved successfully");
char ch ;
while ((ch = getchar()) != '\n' && ch != EOF) ;
printf("\n\nPress ENTER to continue.");
while ((ch = getchar()) != '\n' && ch != EOF) ;
}
/*******************************************************************************************************************************/


/******************************************* SORT FUNCTION *******************************************/

void bubble_sort()
{
for (int i=0 ; i<counter-1 ; i++)
{
    for (int j=0 ; j<counter-i-1;j++)
    {
        if((strcasecmp(arr[j].last_name,arr[j+1].last_name)>0))
        {
            cont temp ;
            temp = arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
}
