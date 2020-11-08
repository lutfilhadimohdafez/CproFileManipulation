#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*1.Construct a database system that contains name and identity card (IC).
This system should have 4 functions that are
addRecord, editRecord, deleteRecord, searchByName, searchByIC.
The name of database file is record.csv. 
*/
int main()
{
    //initialization of program
    printf("File manipulation program.","r");

    //initialization of file variables
    FILE *studentRecord;
    studentRecord = fopen("C:\Users\Lutfil\Documents\CproFileManipulation");
    fprintf(studentRecord, "%s %s %s %d", "We", "are", "in", 2012);

    fclose(studentRecord);

    return 0;
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