// function to display inter-active menu
void Load_menu()
{
	int choice;

	do
	{
		printf("*** Main Menu ***\n\n");
		printf("|1| ADD \n");
		printf("|2| SEARCH \n");
		printf("|3| DELETE \n");
        printf("|4| Print \n");
		printf("|5| MODIFY \n");
		printf("|6| LOAD \n");
		printf("|7| SAVE \n");
        printf("|8| QUIT \n");

		scanf("%d",&choice);

		switch(choice)
		{
			case 1 : ADD();
				break;
			//case 2 : SEARCH();
				break;
           // case 3 : DELETE();
				break;
           // case 4 : PRINT();
				break;
           // case 5 : MODIFY();
				break;
            case 6 :LOAD();
				break;
            case 7 : SAVE();
				break;
			case 8:
                printf("\nyou are quiting without saving !\n");
                printf("\nQuitting program!\n");
				exit(0);
				break;
			default: printf("\nInvalid choice!\n");
				break;
		}

	} while (choice != 8);

}
