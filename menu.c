#ifndef PROJECT_H
#define PROJECT_H
#endif // PROJECT_H
#include <stdio.h> #include <stdlib.h>  #include <string.h> #include <conio.h>  #include "project.h"

/**function to display inter-active menu **/
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
           case 2 : SORT();
			     	break;
           case 7 : SAVE();
				break;
			case 8:
			   Exit();
			default: printf("\n \tInvalid choice!\n");
				break;
		}
		 system("cls");

	} while (1);

}


