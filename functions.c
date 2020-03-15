#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "project.h"

void Load_menu()
{
        system("cls");
int  choice;

	do
	{
		printf("\n\n\t\t\t*** Main Menu ***\n\n");
		printf("\t\t\t|1| ADD \n");
		printf("\t\t\t|2| SORT \n");
		printf("\t\t\t|3| MODIFY \n");
        printf("\t\t\t|4| DELETE \n");
		printf("\t\t\t|5| Print \n");
		printf("\t\t\t|6| SEARCH \n");
		printf("\t\t\t|7| SAVE \n");
        printf("\t\t\t|8| QUIT \n\n\n");

		scanf("%d",&choice);

		switch(choice)
		{
           case 1 : ADD();
				break;
           case 6 : SEARCH();
				break;
           case 4 : DELETE();
				break;
           case 5 : PRINT();
				break;
           case 3 : MODIFY();
				break;
           case 2 : bubble_sort();
			     	break;
           case 7 : SAVE();
				break;
			 case 8 : Exit();
				break;
            default: printf("\n \tInvalid choice!\n");
				break;
	}
	} while (choice != 8);
}


/** Declarations of Structures **/

typedef struct
{
    int day;
    int month;
    int year;
} birth;
typedef struct
{
    char first_name[100];
    char last_name[100];
    birth BD;
    char adress[100];
    char email[100];
    char mob_num[11];
} cont;

/**Global Variable**/
cont arr[100];
int counter=0;


/***** Menu Functions ****/



/******************************************** LOAD FUNCTION *******************************************/
void LOAD ()
{
    system("cls");
    FILE *fRptr ;
    fRptr = fopen("directory.txt","r");
    if (fRptr == NULL)
    {
        printf("\n");
    }
    else
    {
        int count=counter ;
        while(!feof(fRptr))
        {


            fscanf(fRptr,"%[^,],",arr[count].last_name);
            fscanf(fRptr,"%[^,],",arr[count].first_name);
            fscanf(fRptr,"%d-",&arr[count].BD.day);
            fscanf(fRptr,"%d-",&arr[count].BD.month);
            fscanf(fRptr,"%d,",&arr[count].BD.year);
            fscanf(fRptr,"%[^,],",arr[count].email);
            fscanf(fRptr,"%[^,],",arr[count].adress);
            fscanf(fRptr,"%s\n",arr[count].mob_num);
                 // printf("%d",counter);
            count++;
        }
        fclose(fRptr);
        counter=count;
      //  printf("\nUploaded successfully");
    }
}


/******************************************* (1) ADD FUNCTION *******************************************/

void ADD()
{

    system("cls");
    int n ;
    printf("\n\nHow many contacts do you want to add : ");
    scanf("%d",&n);

    for(int i=0 ; i<n; i++)
    {
        printf("\nEnter the last name of contact No.%d:",(i+1));
        scanf("%s",arr[counter].last_name);
        printf("Enter the first name of contact No.%d:",(i+1));
        scanf("%s",arr[counter].first_name);
        printf("Enter the birth date of the contact No.%d:\n",(i+1));
        printf("day: ");
        scanf("%d",&arr[counter].BD.day);
        printf("month: ");
        scanf("%d",&arr[counter].BD.month);
        printf("year: ");
        scanf("%d",&arr[counter].BD.year);
        printf("Enter the address of the contact No.%d:",(i+1));
        scanf(" %[^\t\n]s",arr[counter].adress);
        printf("Enter the email of the contact No.%d:",(i+1));
        scanf(" %[^\t\n]s",arr[counter].email);
        printf("Enter the mobile number of the contact No.%d",(i+1));
        scanf("%s",arr[counter].mob_num);
        printf("\n\n\n______________________________________________________\n");
        counter++;
    }
    flag_s=0;
    printf("add flag_s: %d",flag_s);
    char ch ;
    while ((ch = getchar()) != '\n' && ch != EOF) ;
    printf("\n\nPress ENTER to Back to Menu ......");
    while ((ch = getchar()) != '\n' && ch != EOF) ;
}

/******************************************* (2)SORT FUNCTION *******************************************/

    void bubble_sort()
    {
            system("cls");
          /*  int sort_last ( int );
            int sort_first ( int  );
            int sort_mob( int );*/
            printf("Press\n \t'F' to sort by first name \n\t'L' to sort by last name \n\t'm' to sort by mobile number \n\t'D' to sort bydate of birth\n\t'A' to sort by all respectively ! \n");

                        //comparing last names
          int sort_last ( int j )
             {
                    if((strcasecmp(arr[j].last_name,arr[j+1].last_name)>0))
                    {
                        cont temp ;
                        temp = arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                    printf("==========  sort by last==============\n");
                        return 1 ;

                    }
                    return 0 ;
            }
             //comparing first names
             int  sort_first (int j )
             {
                    if (strcasecmp(arr[j].first_name,arr[j+1].first_name)>0)
                    {
                        cont temp ;
                        temp = arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                    printf("j is %d==========  sort by first==============\n",j);
                        return 1;
                    }
                     return 0 ;
             }

               //comparing mobile numbers
            int  sort_mob (int j )
            {
                        if (strcasecmp(arr[j].mob_num,arr[j+1].mob_num)>0)
                        {
                            cont temp ;
                            temp = arr[j];
                            arr[j]=arr[j+1];
                            arr[j+1]=temp;
                        printf("==========  sort by mob==============\n");
                        }
            }
            //comparing date of birth
            void sort_date(int j)
            {
                if(arr[j].BD.year>arr[j+1].BD.year)
                    {
                        cont temp ;
                        temp = arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                    }
                else if(arr[j].BD.year==arr[j+1].BD.year)
                {

                    if(arr[j].BD.month>arr[j+1].BD.month)
                    {
                        cont temp ;
                        temp = arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                    }
                    else if(arr[j].BD.month==arr[j+1].BD.month)
                    {
                            if(arr[j].BD.day>arr[j+1].BD.day)
                            {
                                cont temp ;
                                temp = arr[j];
                                arr[j]=arr[j+1];
                                arr[j+1]=temp;
                            }

                    }
                }
           }

           void sort_ALL()
            {
                for (int i=0 ; i <counter-1 ; i++)
                {
                    for (int j=0 ; j<counter-i-1; j++)
                    {
                        printf("i is %d j is %d\n",i,j);
                        if (sort_last(j)) printf("\n");
                        else if (sort_first(j)) printf("\n");
                        else if  (sort_mob(j)) printf("\n");
                        else  sort_date(j);
                    }
                }
            }
           switch(getch())
            {
                case 'A' : sort_ALL();
                    break;
                case 'a' : sort_ALL();
                    break;
                case 'F' :
                  {
                    for (int i=0 ; i<counter-1 ; i++)
                    {
                        for (int j=0 ; j<counter-i-1; j++)
                        {
                        sort_first (j );
                        }
                    }
                    break;
                   }
                case 'f':
                    {
                    for (int i=0 ; i<counter-1 ; i++)
                    {
                        for (int j=0 ; j<counter-i-1; j++)
                        {
                        sort_first (j );
                        }
                    }
                    break;
                   }
                case 'L':
                    {
                    for (int i=0 ; i<counter-1 ; i++)
                    {
                        for (int j=0 ; j<counter-i-1; j++)
                        {
                        sort_last ( j );
                        }
                    }
                    break;
                   }

                case 'l':
                   {
                    for (int i=0 ; i<counter-1 ; i++)
                    {
                        for (int j=0 ; j<counter-i-1; j++)
                        {
                        sort_last (j );
                        }
                    }
                    break;
                   }
                case 'M':
                    {
                    for (int i=0 ; i<counter-1 ; i++)
                    {
                        for (int j=0 ; j<counter-i-1; j++)
                        {
                        sort_mob (j );
                        }
                    }
                    break;
                   }
                case 'm':
                    {
                    for (int i=0 ; i<counter-1 ; i++)
                    {
                        for (int j=0 ; j<counter-i-1; j++)
                        {
                        sort_mob (j );
                        }
                    }
                    break;
                   }
                case 'D' :
                    {
                    for (int i=0 ; i<counter-1 ; i++)
                    {
                        for (int j=0 ; j<counter-i-1; j++)
                        {
                            sort_date(j);
                        }
                    }
                    break;
                    }
                case 'd' :
                {
                for (int i=0 ; i<counter-1 ; i++)
                {
                    for (int j=0 ; j<counter-i-1; j++)
                    {
                        sort_date(j);
                    }
                }
                break;
                }

                   default:printf("\n \tInvalid choice!\n");
                    break;
                }


        flag_s=0;
    }
/******************************************* (3)MODIFY FUNCTION *******************************************/


void MODIFY ()
{
    system("cls");
    char target[128] ;
    puts("\nEnter last name of the contact you want to Modify in : ");
    scanf("%s",target);
    for ( int i =0; i < counter; i++)
    {
        if (strcmp(target,arr[i].last_name)==0)
        {

            printf("\nContacts with this last name [%s] : \n ",target);
            printf("contact number.%d\n",i);
            printf("last name is : %s \n",arr[i].last_name);
            printf("first name is :%s \n",arr[i].first_name);
            printf("Date of birth is %d-%d-%d \n",arr[i].BD.day,arr[i].BD.month,arr[i].BD.year);
            printf("address is : %s\n",arr[i].adress);
            printf("email is :%s \n",arr[i].email);
            printf("mobile number is : %s\n",arr[i].mob_num);
            printf("\n");

        }
    }
    int k;
    printf("what is contact number does you want to Modify in :");
    scanf("%d",&k);
    int choice1;
    do
    {
        printf("\n*** Enter what to modify ***\n\n");
        printf( "1:Last name\n2:First name\n3:Address\n4:email\n5:Mobile number\n6:Nothing to modify\n" );
        scanf("%d",&choice1);

        switch(choice1)
        {
        case 1 :
            printf("enter new last name :");
            scanf("%s",arr[k].last_name);
            break;
        case 2 :
            printf("enter new first name :");
            scanf("%s",arr[k].first_name);
             break;
        case 3 :
            printf("enter new birth date :");
            scanf("%d %d %d",arr[k].BD.day,arr[k].BD.month,arr[k].BD.year);
             break;
        case 4 :
            printf("enter new address :");
            scanf("%s",arr[k].adress);
             break;
        case 5 :
            printf("enter new email :");
            scanf("%s",arr[k].email);
             break;
        case 6 :
            printf("enter new mobile number :");
            scanf("%s",arr[k].mob_num);
             break;
        case 7 :
            printf("\nyou are quiting !\n");
            return(0);
        default:
            printf("\nInvalid choice!\n");
            break;
        }
    }
    while (choice1 != 6);

    char ch ;
    while ((ch = getchar()) != '\n' && ch != EOF) ;
    printf("\n\nPress ENTER to continue.");
    while ((ch = getchar()) != '\n' && ch != EOF) ;
flag_s=0;
}


/******************************************* (4) DELETE *******************************************/

void DELETE()
{
    system("cls");
    char target[128] ;
    puts("\nEnter last name of the contact you want to delete : ");
    scanf("%s",target);
    int j=0; int flag1=0;
    for ( int i =0; i < counter; i++)
    {
        if ((strcmp(target,arr[i].last_name)==0))
        {
            flag1 =1;
            printf("\nContacts with this last name [%s] : \n ",target);
            printf("contact number.%d\n",i);
            printf("last name is :%s \n",arr[i].last_name);
            printf("first name is : %s \n",arr[i].first_name);
            printf("Date of birth is %d-%d-%d \n",arr[i].BD.day,arr[i].BD.month,arr[i].BD.year);
            printf("address is : %s\n",arr[i].adress);
            printf("email is :%s \n",arr[i].email);
            printf("mobile number is : %s\n",arr[i].mob_num);
            printf("\n");
            j++;
        }
    }
     if (flag1==1)
     {
    int k;
    printf("what is contact number does you want to delete :");
    scanf("%d",&k);

    /*for(k; k<counter-1; k++)
    {
        arr[k]=arr[k+1];
        flag=1;
    }*/
    printf("counter is before%d",counter);
    printf("k is %d\n",k);
    arr[k]=arr[counter-1];
    counter--;
    printf("counter is after%d",counter);


    printf("\n\n\tDELETED SUCCESSFULLY !\n");
     }
    else printf("\n INvalid LAST NAME !\n ");

    char ch ;
    while ((ch = getchar()) != '\n' && ch != EOF) ;
    printf("\n\nPress ENTER to continue.");
    while ((ch = getchar()) != '\n' && ch != EOF) ;
flag_s=0;
}

/*****************************************(5) PRINT FUNCTION *******************************************/
void PRINT()
{
    system("cls");
    //bubble_sort();
    printf("\n\n\t Printing entire Directory In sorted Order \n\n");
    for (int i=0 ; i<counter; i++)
    {

        printf("\tNo.%d\n",i+1);
        printf("last name is :%s \n",arr[i].last_name);
        printf("first name is : %s \n",arr[i].first_name);
        printf("Date of birth is :%d-%d-%d \n",arr[i].BD.day,arr[i].BD.month,arr[i].BD.year);
        printf("address is : %s\n",arr[i].adress);
        printf("email is :%s \n",arr[i].email);
        printf("mobile number is : %s \n",arr[i].mob_num);
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
    cont target;
        printf("Enter\t[0]\tto skip search by this field ");
        printf("\nEnter the last name to search");
        scanf("%s",target.last_name);
        printf("\n\nEnter\t[0]\tto skip search by this field ");
        printf("Enter the first name to search");
        scanf("%s",target.first_name);
        printf("\n\nEnter\t[0]\tto skip search by this field ");
        printf("\nEnter the birth date to search\n");
        printf("day: ");
        scanf("%d",&target.BD.day);
        printf("month: ");
        scanf("%d",&target.BD.month);
        printf("year: ");
        scanf("%d",&target.BD.year);
        printf("\n\nEnter\t[0]\tto skip search by this field ");
        printf("\nEnter the address to search ");
        scanf("%s",target.adress);
        printf("\n\nEnter\t[0]\tto skip search by this field ");
        printf("\nEnter the email to search");
        scanf(" %[^\t\n]s",target.email);
        printf("\n\nEnter\t[0]\tto skip search by this field ");
        printf("Enter the mobile numbero search");
        scanf(" %[^\t\n]s",target.mob_num);
    int j=1;
    int flag_search=0;

   for ( int i =0; i < counter; i++)
    {
        if( (strcasecmp(target.last_name,arr[i].last_name)==0)|| (strcmp(target.last_name,"0"))==0)
        {
            printf("i: %dlast is true ",i);
            if ((strcasecmp(target.first_name,arr[i].last_name)==0)||strcmp(target.first_name,"0")==0)
                {printf("i: %dfirst is true ",i);
                    if((target.BD.day==arr[i].BD.day||target.BD.day == 0))
                        {
                            if ( (target.BD.month==arr[i].BD.month)|| (target.BD.month==0))
                            {
                                if ( (target.BD.year==arr[i].BD.year)|| (target.BD.year==0))
                                {
                                    if ( (strcasecmp(target.adress,arr[i].adress)==0)|| (strcasecmp(target.adress,"0")==0))
                                    {
                                         if ( (strcasecmp(target.email,arr[i].email)==0)|| (strcasecmp(target.email,"0")==0))
                                         {
                                              if ( (strcasecmp(target.mob_num,arr[i].mob_num)==0)|| (strcasecmp(target.mob_num,"0")==0))
                                              {
                                                    printf("\nContacts with this last name [%s] : \n ",target);
                                                    printf("\tNo.%d\n",j);
                                                    printf("last name is :%s \n",arr[i].last_name);
                                                    printf("first name is : %s \n",arr[i].first_name);
                                                    printf("Date of birth is %d-%d-%d \n",arr[i].BD.day,arr[i].BD.month,arr[i].BD.year);
                                                    printf("address is : %s\n",arr[i].adress);
                                                    printf("email is :%s \n",arr[i].email);
                                                    printf("mobile number is : %s\n",arr[i].mob_num);
                                                    printf("\n");
                                                    j++;
                                                    flag_search=1;
                                              }

                                         }

                                    }

                                }
                            }
                        }
                }
        }

    }
    if (!flag_search){   printf(" this name doesn't exist in directory  ");}
    char ch ;
    while ((ch = getchar()) != '\n' && ch != EOF) ;
   printf("\n\nPress ENTER to Back to Main Menu ......");
    while ((ch = getchar()) != '\n' && ch != EOF) ;

}
/******************************************* (7)SAVE FUNCTION *******************************************/

void SAVE()
{
    system("cls");
    FILE*fptr;
    fptr=fopen("directory.txt","w+");
    fseek(fptr,0,SEEK_SET);
    printf("%d",counter);
    for(int i=0; i<counter; i++)
    {

        fprintf(fptr,"%s,%s,%d-%d-%d,%s,%s,%s\n",arr[i].last_name,arr[i].first_name,arr[i].BD.day,arr[i].BD.month,arr[i].BD.year,
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
flag_s=1;
}
/*******************************************************************************************************************************/
void Exit ()
{
    system("cls");
    printf("add flag_s: %d",flag_s);
    if (flag_s==1)
    {
       exit(0);
    }
    else
    {
        printf("Do you want to save changes you made?\n");
        char answer;
        printf("'Y'for yes\t 'N'for no\t 'B'for back to main menu: \n ");

        switch(getch())
        {
                case 'Y': SAVE();
                printf("\n \n \t Quitting program!\n\n");
                exit(0);
                 case 'y': SAVE();printf("\n \n \t Quitting program!\n\n");exit(0);
                case 'N': printf("\n \n \t Quitting program!\n\n"); exit(0);
                case 'n': printf("\n \n \t Quitting program!\n\n"); exit(0);
                case 'B':Load_menu(); break;
                case 'b':Load_menu();break;
                default: printf("\n \tInvalid nnnchoice!\n");
                break;
        }
    }

}
