#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*1.Construct a database system that contains name and identity card (IC).
This system should have 4 functions that are
addRecord, editRecord, deleteRecord, searchByName, searchByIC.
The name of database file is record.csv. 
*/
void readRecord();

int main()
{
    //initialization of program
    printf("File manipulation program.");

    readRecord();

    //initialization of file variables

    //reading file

    return 0;
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