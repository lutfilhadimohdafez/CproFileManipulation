#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*1.Construct a database system that contains name and identity card (IC).
This system should have 4 functions that are
addRecord, editRecord, deleteRecord, searchByName, searchByIC.
The name of database file is record.csv. 
*/
void readRecord();
void mainMenu();

int main()
{
    //initialization of program
    printf("\n\n----------File manipulation program.----------\n\n");
    //main menu function to choose
    mainMenu();
    //readRecord();

    return 0;
}

void mainMenu()
{
    int userInput;
    char menuChoice[5][20] = {
        "Read Record",
        "Add Record",
        "Edit Record",
        "Delete Record",
        "Search"};
    for (int i = 0; i < 5; i++)
    {
        printf("\t%d.", i + 1);
        printf("%s\n", menuChoice[i]);
    }
    printf("\tPlease input the number of choice:");
    scanf("%d",&userInput);
    switch (userInput)
    {
    case 1:
        printf("\nCase1: Value is: %d", userInput);
        break;
    case 2:
        printf("\nCase1: Value is: %d", userInput);
        break;
    case 3:
        printf("\nCase1: Value is: %d", userInput);
        break;
    default:
        printf("\nDefault: Value is: %d", userInput);
    }
}

void readRecord()
{
    FILE *studentRecord;
    studentRecord = fopen("record.csv", "r");
    char buffer[255] = {0};
    if (studentRecord == NULL)
    {
        printf("\n Failed to open file!");
    }
    else
    {
        while ((fgets(buffer, 255, studentRecord)) != NULL)
        {
            puts(buffer);
            /* Some processing */
        }
        fclose(studentRecord);
    }
}

int addRecord()
{
    return 0;
}

int editRecord()
{
    return 0;
}

int deleteRecord()
{
    return 0;
}

int searchByName()
{
    return 0;
}

int searchByIC()
{
    return 0;
}