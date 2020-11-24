
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>


int mainMenu();
void printValues();
void dataCheck();
int editRecord();
int addRecord();
int deleteRecord();
int searchByName();
int searchByIC();
int delay();


FILE *customerRecord;

typedef struct customerInfo
{
    char custId[10];
    char custIC[255];
    char custName[255];
    char custContactNum[255];

} custInfo;

char temp[255];
char *storeIndex[255];
int searchArr[255];

int main()
{

    system("cls");
    system("color 02");
    char continueProgram = 'Y';
    //initialization of program to parse data from csv into struct array
    customerRecord = fopen("recordCust.csv", "r");
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
    do
    {
        system("cls");
        system("echo [101;93m ----------Warung Makcik Bawang---------- [0m");
        //printf("\n\n----------Warung Makcik Bawang----------\n\n");
        mainMenu(values, &customerRecord);
        printf("\n\tDo you wish to continue?(Y/N)");
        scanf(" %c", &continueProgram);
    } while (continueProgram == 'Y');

    return 0;
}

int mainMenu(custInfo values[], FILE *customerRecord)
{
    //declaring user input variable
    int userInput;
    //char searchInput;
    //below array for menu choice strings
    char menuChoice[6][90] = {
        "Display All Cust Info",
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
            //readRecord();
            printValues(values);
            break;
        case 2:
            //add record

            delay(1);
            addRecord();
            break;
        case 3:
            //edit record

            delay(1);
            editRecord(values, customerRecord);
            break;
        case 4:
            //delete record

            delay(1);
            deleteRecord();
            break;
        case 5:

            delay(1);
            searchByName(values);
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
    return 0;
}

int addRecord()
{
    return 0;
}

int editRecord(custInfo values[], FILE *customerRecord)
{
    return 0;
}

int deleteRecord()
{
    return 0;
}

int searchByName(custInfo values[])
{
    int w = 0, x = 0, y = 0, z = 0;
    char *p;
    printf("\n\tEnter customer's name:");
    fflush(stdin);
    gets(temp);
    printf("\n");
    for (int i = 0; i < 100; i++)
    {
        p = strstr(values[i].custName, temp);
        if (p != NULL)
        {
            printf("\tCust ID: %s\tCust IC: %s", values[i].custId, values[i].custIC);
            printf("\tCust Name: %s\t\tContactNo: %s", values[i].custName, values[i].custContactNum);
            searchArr[x] = i;
            //printf("%p",storeIndex);
            x++;
        }
    }
    // for(int d=0;d<100;d++){
    //     printf("%d",d);
    //     printf("%d\n",searchArr[d]);
    // }
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
    return 0;
}

void dataCheck(custInfo values[], FILE *customerRecord)
{
}

void printValues(custInfo values[])
{
    printf("\n");
    for (int i = 0; i < 100; i++)
    {
        if (values[i].custId != "\0")
        {
            printf("\tCust ID: %s\tCust IC: %s", values[i].custId, values[i].custIC);
            printf("\tCust Name: %s\t\tContactNo: %s", values[i].custName, values[i].custContactNum);
        }
    }
}
