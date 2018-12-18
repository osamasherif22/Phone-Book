#include <conio.h> #include <stdlib.h>
/**function to display inter-active menu **/
void Load_menu()
{
	int choice;

	do
	{
		printf("\n\n*** Main Menu ***\n\n");
		printf("|1| ADD \n");
		printf("|2| LOAD \n");
		printf("|3| MODIFY \n");
        printf("|4| DELETE \n");
		printf("|5| Print \n");
		printf("|6| SEARCH \n");
		printf("|7| SAVE \n");
        printf("|8| QUIT \n\n\n");

		scanf("%d",&choice);

		switch(choice)
		{
           case 1 : ADD();
                    bubble_sort();
				break;
           case 6 : SEARCH();
				break;
           case 4 : DELETE();
				break;
           case 5 : PRINT();
				break;
           case 3 : MODIFY();
                  bubble_sort();
				break;
           case 2 : LOAD();
                    bubble_sort();
			     	break;
           case 7 : SAVE();
				break;
			case 8:
			    system("cls");
                printf("\n \n Quitting program!\n\n");
				exit(0);
				break;
			default: printf("\nInvalid choice!\n");
				break;
		}
		 system("cls");

	} while (choice != 8);

}
