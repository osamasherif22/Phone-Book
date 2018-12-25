#include <stdio.h> #include <stdlib.h>  #include <string.h> #include <conio.h>  #include "project.h"

/** Declarations of Structures **/
int flag_s =0 ;

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
    char mob_num[64];
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

        while(!feof(fRptr))
        {



            fscanf(fRptr,"%[^,],",arr[counter].last_name);
            fscanf(fRptr,"%[^,],",arr[counter].first_name);
            fscanf(fRptr,"%d-",&arr[counter].BD.day);
            fscanf(fRptr,"%d-",&arr[counter].BD.month);
            fscanf(fRptr,"%d,",&arr[counter].BD.year);
            fscanf(fRptr,"%[^,],",arr[counter].email);
            fscanf(fRptr,"%[^,],",arr[counter].adress);
            fscanf(fRptr,"%s\n",arr[counter].mob_num);



            counter++;

        }
        fclose(fRptr);

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
        int check_ln;
        do{
        scanf(" %[^\t\n]s",arr[counter].last_name);
        check_ln = validate_string((arr[counter].last_name));
        }while(!check_ln);


        printf("Enter the first name of contact No.%d:",(i+1));
        int check_fn;
        do{
        scanf(" %[^\t\n]s",arr[counter].first_name);
        check_ln =validate_string((arr[counter].first_name));
        }while(!check_ln);

        printf("Enter the birth date of the contact No.%d:\n",(i+1));
        printf("day: ");
        int check_d;
        do{
        scanf("%d",&arr[counter].BD.day);
        check_d = validate_day(arr[counter].BD.day);
        }while(!check_d);

        printf("month: ");
        int check_mon;
        do{
        scanf("%d",&arr[counter].BD.month);
        check_mon = validate_month(arr[counter].BD.month);
        }while(!check_mon);

        printf("year: ");
        int check_year,numofdig;
        do{
        scanf("%d",&arr[counter].BD.year);
        numofdig=count(arr[counter].BD.year);
        check_year = validate_year(arr[counter].BD.year,numofdig);
        }while(!check_year);

        printf("Enter the address of the contact No.%d:",(i+1));
        scanf(" %[^\t\n]s",arr[counter].adress);
        printf("Enter the email of the contact No.%d:",(i+1));
        scanf(" %[^\t\n]s",arr[counter].email);
        printf("Enter the mobile number of the contact No.%d",(i+1));
         int check_m;
        do{
        scanf("%s",arr[counter].mob_num);
        check_m = validate_num(arr[counter].mob_num);
        }while(!check_m);
        printf("\n\n\n______________________________________________________\n");
        counter++;
    }
flag_s=0;
    char ch ;
    while ((ch = getchar()) != '\n' && ch != EOF) ;
    printf("\n\nPress ENTER to Back to Menu ......");
    while ((ch = getchar()) != '\n' && ch != EOF) ;
}

/******************************************* (2)SORT FUNCTION *******************************************/
void SORT()
{
    system("cls");
    /*  int sort_last ( int );
      int sort_first ( int  );
      int sort_mob( int );*/
    //printf("Press\n \t |F| to sort by first name \n\t'L' to sort by last name \n\t'm' to sort by mobile number \n\t'D' to sort bydate of birth\n\t'A' to sort by all respectively ! \n");
    printf("\n\tChoose WHat To Sort With .... \n");
    printf("\n\n\t\t*** OPTIONS ***\n\n");
    printf("\t\t [A] ALL \n");
    printf("\t\t [F] FIRST NAME \n");
    printf("\t\t [L] LAST NAME \n");
    printf("\t\t [M] MOBILE NUMBER \n");
    printf("\t\t [D] DATE OF BIRTH \n");

    switch(getch())
    {
    case 'A' :
    case 'a' :
        sort_ALL();

        char ch ;
        while ((ch = getchar()) != '\n' && ch != EOF) ;
        printf("\n\n\tSORTED COMPLETED\n\n");
        printf("\n\nPress ENTER to Back to Main menu  .....");
        while ((ch = getchar()) != '\n' && ch != EOF) ;
        break;
    case 'F' :
    case 'f':
    {
        for (int i=0 ; i<counter-1 ; i++)
        {
            for (int j=0 ; j<counter-i-1; j++)
            {
                sort_first (j );
            }
        }
        char ch ;
        while ((ch = getchar()) != '\n' && ch != EOF) ;
        printf("\n\n\tSORTED COMPLETED\n\n");
        printf("\n\nPress ENTER to Back to Main menu  .....");
        while ((ch = getchar()) != '\n' && ch != EOF) ;
        break;
    }
    case 'L':
    case 'l':
    {
        for (int i=0 ; i<counter-1 ; i++)
        {
            for (int j=0 ; j<counter-i-1; j++)
            {
                sort_last (j );
            }
        }

        char ch ;
        while ((ch = getchar()) != '\n' && ch != EOF) ;
        printf("\n\n\tSORTED COMPLETED\n\n");
        printf("\n\nPress ENTER to Back to Main menu  .....");
        while ((ch = getchar()) != '\n' && ch != EOF) ;
        break;
    }
    case 'M':
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
    case 'd' :
    {
        for (int i=0 ; i<counter-1 ; i++)
        {
            for (int j=0 ; j<counter-i-1; j++)
            {
                sort_date(j);
            }
        }

        char ch ;
        while ((ch = getchar()) != '\n' && ch != EOF) ;
        printf("\n\n\tSORTED COMPLETED\n\n");
        printf("\n\nPress ENTER to Back to Main menu  .....");
        while ((ch = getchar()) != '\n' && ch != EOF) ;
        break;
    }

    default:
        printf("\n \tInvalid choice!\n");
        break;
    }


    flag_s=0;
}

/*
void bubble_sort()
{
        system("cls");
    for (int i=0 ; i<counter-1 ; i++)
    {
        for (int j=0 ; j<counter-i-1; j++)
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

  flag_s=0;

}
*/


/******************************************* (3)MODIFY FUNCTION *******************************************/


void MODIFY ()
{
    system("cls");
    char target[128] ;
    puts("\nEnter last name of the contact you want to Modify in : ");
    scanf("%s",target);
    int j=0 ;
    int a[100];
    int flag_mod=0 ;
    int fflag;
    int i;
    for (i =0; i < counter; i++)
    {
        if (strcasecmp(target,arr[i].last_name)==0)
        {
            flag_mod=1;
            printf("\nContacts with this last name [%s] : \n ",target);
            printf("\n\tNo.%d\n",i);
            printf("last name is : %s \n",arr[i].last_name);
            printf("first name is :%s \n",arr[i].first_name);
            printf("Date of birth is %d-%d-%d \n",arr[i].BD.day,arr[i].BD.month,arr[i].BD.year);
            printf("address is : %s\n",arr[i].adress);
            printf("email is :%s \n",arr[i].email);
            printf("mobile number is : %s\n",arr[i].mob_num);
            printf("\n");
            a[j]=i;
            j++;


        }
    }
    //if (flag_mod==0)  printf("\n INvalid LAST NAME !\n "); exit(0);
    if (flag_mod==0)
    {
        printf("\nINvalid last name !\n");
        char ch ;
        while ((ch = getchar()) != '\n' && ch != EOF) ;
        printf("\n\nPress ENTER to Main .....");
        while ((ch = getchar()) != '\n' && ch != EOF) ;
        return;
    }
    if(j==1)
    {
        int choice0;
        do
        {
            fflag=1;
            printf("\n*** Enter what to modify ***\n\n");
            printf( "1:Last name\n2:First name\n3:BirthDate\n4:Address\n5:E-mail\n6:Mobile number\n7:Nothing To Modify\n" );
            scanf("%d",&choice0);

            switch(choice0)
            {
            case 1 :
                printf("enter new last name :");
                scanf("%s",arr[a[0]].last_name);
                flag_s=0;

                break;
            case 2 :
                printf("enter new first name :");
                scanf("%s",arr[a[0]].first_name);
                flag_s=0;

                break;
            case 3 :
                printf("enter new birth date :");
                printf("enter new birth [day] :");
                scanf("%d",&arr[a[0]].BD.day);
                printf("enter new birth [month] :");
                scanf("%d",&arr[a[0]].BD.month);
                printf("enter new birth [year] :");
                scanf("%d",&arr[a[0]].BD.year);
                flag_s=0;

                break;
            case 4 :
                printf("enter new address :");
                scanf("%s",arr[a[0]].adress);
                flag_s=0;

                break;
            case 5 :
                printf("enter new email :");
                scanf("%s",arr[a[0]].email);
                flag_s=0;

                break;
            case 6 :
                printf("enter new mobile number :");
                scanf("%s",arr[a[0]].mob_num);
                flag_s=0;

                break;

            case 7 :
                printf("\nyou are quiting from modify !\n");

                char ch ;
                while ((ch = getchar()) != '\n' && ch != EOF) ;
                printf("\n\nPress ENTER to Back to main menu ...... \n");
                while ((ch = getchar()) != '\n' && ch != EOF) ;

                return;
            default:
                printf("\nInvalid choice!\n");
                char ch21 ;
                while ((ch21 = getchar()) != '\n' && ch21 != EOF) ;
                printf("\n\nPress ENTER to Back to Modify menu ...... \n");
                while ((ch21 = getchar()) != '\n' && ch21 != EOF) ;
                break;
            }

        }
        while (choice0 != 7);
    }


    /***********/


    int k;
    printf("what is contact number does you want to Modify in :");
    scanf("%d",&k);
    for (int n=0; n<j; n++)
    {

        if(a[n]==k)
        {
            int choice1;
            do
            {
                fflag=1;
                printf("\n*** Enter what to modify ***\n\n");
                printf( "1:Last name\n2:First name\n3:BirthDate\n4:Address\n5:E-mail\n6:Mobile number\n7:Nothing To Modify\n" );
                scanf("%d",&choice1);

                switch(choice1)
                {
                case 1 :
                    printf("enter new last name :");
                    scanf("%s",arr[k].last_name);
                    flag_s=0;

                    break;
                case 2 :
                    printf("enter new first name :");
                    scanf("%s",arr[k].first_name);
                    flag_s=0;

                    break;
                case 3 :
                    printf("\nenter new birth date :\n");
                    printf("enter new birth [day] :");
                    scanf("%d",&arr[k].BD.day);
                    printf("\tenter new birth [month] :");
                    scanf("%d",&arr[k].BD.month);
                    printf("\tenter new birth [year] :");
                    scanf("%d",&arr[k].BD.year);
                    flag_s=0;

                    break;
                case 4 :
                    printf("enter new address :");
                    scanf("%s",arr[k].adress);
                    flag_s=0;

                    break;
                case 5 :
                    printf("enter new email :");
                    scanf("%s",arr[k].email);
                    flag_s=0;

                    break;
                case 6 :
                    printf("enter new mobile number :");
                    scanf("%s",arr[k].mob_num);
                    flag_s=0;

                    break;
                case 7 :
                    printf("\nyou are quiting from modify !\n");

                    char ch ;
                    while ((ch = getchar()) != '\n' && ch != EOF) ;
                    printf("\n\nPress ENTER to Back to main menu ...... \n");
                    while ((ch = getchar()) != '\n' && ch != EOF) ;

                    return;
                default:
                    printf("\nInvalid choice!\n");
                    char ch22 ;
                    while ((ch22 = getchar()) != '\n' && ch22 != EOF) ;
                    printf("\n\nPress ENTER to Back to Modify menu ...... \n");
                    while ((ch22 = getchar()) != '\n' && ch22 != EOF) ;
                    break;
                }

            }
            while (choice1 != 7);


        }
        else
            continue;
    }

    if(fflag!=1)
    {
        char ch ;
        while ((ch = getchar()) != '\n' && ch != EOF) ;

        printf("\n\n INvalid choice ! \n ");
        printf("\n\nPress ENTER to Back to main menu ....... \n");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
        return;
    }

}

/******************************************* (4) DELETE *******************************************/

void DELETE()
{
    system("cls");
    char target[128] ;
    puts("\nEnter last name of the contact you want to delete : ");
    scanf("%s",target);
    int flag_dele=0;
    int j =0;
    int a[100];
    for ( int i =0; i < counter; i++)
    {
        if ((strcasecmp(target,arr[i].last_name)==0))
        {
            flag_dele =1;
            printf("\nContacts with this last name [%s] : \n ",target);
            printf("\n\tNo.%d\n",i);
            printf("last name is :%s \n",arr[i].last_name);
            printf("first name is : %s \n",arr[i].first_name);
            printf("Date of birth is %d-%d-%d \n",arr[i].BD.day,arr[i].BD.month,arr[i].BD.year);
            printf("address is : %s\n",arr[i].adress);
            printf("email is :%s \n",arr[i].email);
            printf("mobile number is : %s\n",arr[i].mob_num);
            printf("\n");
            a[j]=i;
            j++;

        }
    }
    if (flag_dele==1)
    {

        int k;
        printf("what is contact number does you want to delete : ");
        scanf("%d",&k);
        for (int n=0; n<j; n++)
        {

            if(a[n]==k)
            {
                arr[k]=arr[counter-1];
                counter--;
                flag_s=0;
                printf("\n\n\t DELETED SUCCESSFULLY !\n");
                break ;
            }
            else
                printf(" \nInvalid choice !\n");
        }

        /*for(k; k<counter-1; k++)
        {
            arr[k]=arr[k+1];
            flag=1;
        }*/

        //printf("counter is before%d",counter);
        //printf("k is %d\n",k);
        //printf("counter is after%d",counter);


    }
    else
        printf("\n INvalid LAST NAME !\n ");

    char ch ;
    while ((ch = getchar()) != '\n' && ch != EOF) ;
    printf("\n\nPress ENTER to Back to Main Menu ......");
    while ((ch = getchar()) != '\n' && ch != EOF) ;
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
    printf("\n\nPress ENTER to Back to Main Menu ......");
    while ((ch = getchar()) != '\n' && ch != EOF) ;

}
/******************************************* (6)SEARCH FUNCTION *******************************************/
void SEARCH()
{
    system("cls");
    char target[128] ;
    puts("\nEnter last name you want to search with : ");
    scanf("%s",target);
    int j=1;            int flag_ser=0;

    for ( int i =0; i < counter; i++)
    {

        if ((strcasecmp(target,arr[i].last_name)!=0))
            continue;

       else if ((strcasecmp(target,arr[i].last_name)==0))
        {
            flag_ser=1;
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
        }

    }
      if (flag_ser==0)         printf(" \nInvalid choice !\n");


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
    flag_s=1;
    system("cls");
    printf("\n\nSaved successfully");
    char ch ;
    while ((ch = getchar()) != '\n' && ch != EOF) ;
    printf("\n\nPress ENTER to continue  ......");
    while ((ch = getchar()) != '\n' && ch != EOF) ;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
int validate_string(char *string)
{
    int flag_y ;
    //  scanf("%s",string[]);
    for(int k=0; k<strlen(string); k++)
    {
        if((string[k]>=97&&string[k]<=122)||(string[k]>=65&&string[k]<=90))
            flag_y = 1;
        else
        {
            flag_y =0;
            printf(" [Please Re-enter a right name :]\n");
            break;
        }
        //printf("flag_fn%d\n",flag_ln);

    }
    return flag_y;
}
/*******************************************************************************************************************************/
int validate_num(char *number)
{

    int i,flag_m=1;

    for (i=0; i<strlen (number); i++)
    {
        if ( !(isdigit(number[i])) || number[0]<=45 || number[0]!=48)
        {
            printf("[Please Re-enter a right mobile number :]\n");
            flag_m=0;
            break;
        }
    }

    return flag_m;
}


/*******************************************************************************************************************************/

void Exit ()
{
    system("cls");
    if (flag_s==1)
    {
        printf("\n \n \t Quitting program!\n\n");

        exit(0);
    }
    else
    {
        printf("\n\tDo you want to save changes you made?\n");
        //char answer;

        printf("\n\n\t\t*** OPTIONS ***\n\n");
        printf("\t\t [Y] YES \n");
        printf("\t\t [N] NO \n");
        printf("\t\t [B] BACK TO MAIN MENU \n");


        switch(getch())
        {
        case 'y':
        case 'Y':
            SAVE();
            printf("\n \n \t Quitting program!\n\n");
            exit(0);

        case 'n':
        case 'N':
            printf("\n \n \t Quitting program!\n\n");
            exit(0);

        case 'b':
        case 'B':
            system("cls");
            Load_menu();
            break;

        default:
            printf("\n \tInvalid choice!\n");

            char ch ;
            while ((ch = getchar()) != '\n' && ch != EOF) ;
            printf("\n\nPress ENTER to Back to Main Menu ......");
            while ((ch = getchar()) != '\n' && ch != EOF) ;
            break ;
        }
    }


}
/*******************************************************************************************************************************/

/******************************************* SORTING OPTIONS *****************************************************************/

//comparing last names
int sort_last ( int j )
{
    if((strcasecmp(arr[j].last_name,arr[j+1].last_name)>0))
    {
        cont temp ;
        temp = arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        return 1 ;

    }
    return 0 ;
}
/**********************************************************************************************************************/
/**comparing first names**/
int  sort_first (int j )
{
    if (strcasecmp(arr[j].first_name,arr[j+1].first_name)>0)
    {
        cont temp ;
        temp = arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        return 1;
    }
    return 0 ;
}
/**********************************************************************************************************************/
/**comparing mobile numbers**/
int  sort_mob (int j )
{
    if (strcasecmp(arr[j].mob_num,arr[j+1].mob_num)>0)
    {
        cont temp ;
        temp = arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;

    }
}
/**********************************************************************************************************************/
/**comparing date of birth**/
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


/**********************************************************************************************************************/

void sort_ALL()
{
    for (int i=0 ; i <counter-1 ; i++)
    {
        for (int j=0 ; j<counter-i-1; j++)
        {

            if (sort_last(j))
                printf("\n");
            else if (sort_first(j))
                printf("\n");
            else if  (sort_mob(j))
                printf("\n");
            else
                sort_date(j);
        }
    }
}
/**********************************************************************************************************************/
int count(int number)
{
    int numofdig=0 ;
    while (number!=0)
    {
        number= number/10;
        numofdig++;
    }
    return numofdig ;

}

/*******************************************************************************************************************************/
int validate_day(int number){
    int flag_m=1;
        if ( number>31 || number<=0)
        {
        printf("[Please Re-enter a right Day !] :\n");
            flag_m=0;
        }


        return flag_m;
}
/*******************************************************************************************************************************/
int validate_month(int number){
    int flag_m=1;
        if ( number>12 || number<=0)
        {

        printf("[Please Re-enter a right Month !] :\n");
            flag_m=0;
        }


        return flag_m;
}
/*******************************************************************************************************************************/
int validate_year(int number,int numofdig){
    int flag_m=1;
        if ( numofdig != 4 || number<=0)
        {

        printf("[Please Re-enter a right Year !] :\n");
            flag_m=0;
        }


        return flag_m;
}


