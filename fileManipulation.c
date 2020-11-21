//Preprocessors
//Restaturant management system using C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
//Soalan Assignment
/*1.Construct a database system that contains name and identity card (IC).
This system should have 4 functions that are
addRecord, editRecord, deleteRecord, searchByName, searchByIC.
The name of database file is record.csv. 
*/

// Function prototype untuk user-defined functions
int mainMenu();
void readRecord();
void printValues();
int editRecord();
int addRecord();
int deleteRecord();
int searchByName();
int searchByIC();
int delay();

//Global Variable
FILE *customerRecord;

typedef struct customerInfo
{
    char custId[10];
    char custIC[255];
    char custName[255];
    char custContactNum[255];

} custInfo;

//main Program function
int main()
{
    //initializing the program loop variable, default set as Y(yes)
    system("cls");
    system("color 02");
    char continueProgram = 'Y';
    //initialization of program
    
    //main menu function to choose
    do
    {
        system("cls");
        printf("\n\n----------Warung Makcik Bawang----------\n\n");
        mainMenu();
        printf("\n\tDo you wish to continue?(Y/N)");
        scanf(" %c", &continueProgram);
    } while (continueProgram == 'Y');

    return 0;
}

int mainMenu()
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
    printf("\n\tPlease input the number of choice:");
    scanf("%d", &userInput);
    if (userInput < 1)
    {
        printf("Wrong Number");
    }
    if (userInput >= 1 && userInput <= 6)
    {
        printf("\n\tSelected choice:%d, doing %s\n", userInput, menuChoice[userInput - 1]);
        switch (userInput)
        {
        case 1:
            //Read record

            delay(1);
            readRecord();
            //printValues();
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
            return 0;
        }
    }
    if (userInput >= 7)
    {
        printf("\n\tWrong number choice, returning to main menu\n");
        return 0;
    }
    // else{
    //     printf("\n\tInput error, returning to main menu\n");
    //     return 0;
    // }
}

void readRecord()
{
    customerRecord = fopen("record.csv", "r");
    char buffer[1024];
    int row_count = 0;
    int column_count = 0;

    custInfo values[100];

    int i = 0;
    while (fgets(buffer, 1024, customerRecord))
    {
        //printf("%s\n", buffer);//ni utk test masukkan kat dalam array
        column_count = 0;
        row_count++;
        if (row_count == 1)
        {
            continue;
        }
        char *column = strtok(buffer, ",");
        //column = malloc(15);
        while (column)
        {
            if (column_count == 0)
            {
                strcpy(values[i].custId, column);
            }
            if (column_count == 1)
            {
                strcpy(values[i].custIC, column);
            }
            if (column_count == 2)
            {
                strcpy(values[i].custName, column);
            }
            if (column_count == 3)
            {
                strcpy(values[i].custContactNum, column);
            }

            column = strtok(NULL, ",");
            column_count++;
        }
        i++;
    }
    fclose(customerRecord);
    printValues(values);
    // char buffer[10] = {0};
    // if (customerRecord == NULL)
    // {
    //     printf("\n Failed to open file!");
    // }
    // else
    // {
    //     while ((fgets(buffer, 255, customerRecord)) != NULL)
    //     {
    //         puts(buffer);
    //         /* Some processing */
    //         //delay(1);
    //     }
    //     fclose(customerRecord);
    // }
}

int addRecord()
{
    // char id[255], firstName[255], appName[255];
    // customerRecord = fopen("record.csv", "a");
    // fprintf(customerRecord, "");
    // fclose(customerRecord);
    // return 0;
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

void printValues(custInfo values[])
{
    printf("\n");
    for (int i = 0; i < 100; i++)
    {
        printf("\tCust ID: %s\tCust IC: %s", values[i].custId, values[i].custIC);
        printf("\tCust Name: %s\t\tContactNo: %s", values[i].custName, values[i].custContactNum);
    }
}