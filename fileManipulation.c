#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/*1.Construct a database system that contains name and identity card (IC).
This system should have 4 functions that are
addRecord, editRecord, deleteRecord, searchByName, searchByIC.
The name of database file is record.csv. 
*/

// Function prototype untuk user define functions
void mainMenu();
void readRecord();
int editRecord();
int addRecord();
int deleteRecord();
int searchByName();
int searchByIC();
int delay();

//main Program function
int main()
{
    //initializing the program loop variable, default set as Y(yes)
    char continueProgram = 'Y';
    //initialization of program
    printf("\n\n----------File manipulation program.----------\n\n");
    //main menu function to choose
    do
    {
        mainMenu();
        printf("\n\tDo you wish to continue?(Y/N)");
        scanf(" %c", &continueProgram);
    } while (continueProgram == 'Y');

    return 0;
}

void mainMenu()
{
    //declaring user input variable
    int userInput;
    char searchInput;
    //below array for menu choice strings
    char menuChoice[6][20] = {
        "Read Record",
        "Add Record",
        "Edit Record",
        "Delete Record",
        "Search by Name",
        "Search by IC"};
    for (int i = 0; i < 6; i++)
    {
        printf("\t%d.", i + 1);
        printf("%s\n", menuChoice[i]);
    }
    printf("\tPlease input the number of choice:");
    scanf("%d", &userInput);
    printf("\nSelected choice:%d, doing %s\n", userInput, menuChoice[userInput - 1]);
    switch (userInput)
    {
    case 1:
        //Read record
        
        delay(1);
        readRecord();
        break;
    case 2:
        //add record

        delay(1);
        addRecord();
        break;
    case 3:
        //edit record

        delay(1);
        editRecord();
        break;
    case 4:
        //delete record

        delay(1);
        deleteRecord();
        break;
    case 5:

        delay(1);
        searchByName();
        break;
    case 6:

        delay(1);
        searchByIC();
        break;
    default:
        printf("\n Input Error %d");
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
            //delay(1);
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
    printf("HEY DUMB IM SEARCHING BY NAME");
    return 0;
}

int searchByIC()
{
    printf("HEY DUMB IM SEARCHING BY IC");
    return 0;
}

int delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}