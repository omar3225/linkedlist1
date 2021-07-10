#include<stdlib.h>
#include<string.h>
#include<stdio.h>
 
struct student
    {
    char name[50];
	int id;
	int day, month, year;
	int lyscore;
    };
struct student a;


int main()
{
    int choice;
    while(1)
    {
        printf("\n\n***MAIN MENU ***\n");
        printf("1. linked list\n2. dynamic array\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:  linked_list();  break;
            case 2:  dynamic_array(); break;
            case 3:  goto label;
            default: printf("\nWrong selection!!! Please try again!!!\n");
        }
    }
    label:
    return 0;
}