/*
#include <conio.h>
#include <stdlib.h>
//#include "project.h"


function to display inter-active menu
void Load_menu()
{
	int choice;

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
			case 8:
			    system("cls");
              //  printf("\n \n \t Quitting program!\n\n");
              if ( flag_s==1)
                {

               exit(0);

                }
                else if (flag_s==0)
                {
                    printf("Do you want to save changes you made?");
                    char answer;
                    printf("'Y' for yes 'N' for no 'C' for cancel ");
                   scanf("%c",&answer);
                    switch(answer)
                    {
                        case 'Y':	SAVE();
                            exit(0);
                        case 'N':
                            exit(0);
                        case 'C':
                            break;
                    default: printf("\n \tInvalid choice!\n");
                    }

                }
				printf("%d",flag_s);
			default: printf("\n \tInvalid choice!\n");
				break;
		}
		 system("cls");

	} while (choice != 8);

}
*/
