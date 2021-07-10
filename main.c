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


void linked_list()
{
    int list_count=0;

    struct node
    {
        struct student data;
        struct node* next;
    };

    struct node* head = NULL;
    struct node* tail = NULL;

    void read_data()
    {
        printf("Enter the name of the student \n");
        fflush(stdin);
        gets(a.name);

        printf("Enter the day of birth of the student \n");
        scanf("%d",&a.day);

        printf("Enter the month of birth of the student \n");
        scanf("%d",&a.month);

        printf("Enter the year of birth of the student \n");
        scanf("%d",&a.year);

        printf("Enter the Id of the student \n");
        scanf("%d",&a.id);

        printf("Enter the last year mark of the student \n");
        scanf("%d",&a.lyscore);
    }

    void printlist ()
    {
        struct node* ptr = NULL;
        ptr = head;
        printf("-----------------------------------------------------------------------------------\n");
        while (ptr != NULL)
        {
            printf("Name: %s",ptr->data.name);
            printf("\nID: %d",ptr->data.id);
            printf("\nDate: %d/%d/%d",ptr->data.day,ptr->data.month,ptr->data.year);
            printf("\nLast year score: %d",ptr->data.lyscore);
            ptr = ptr->next;
            printf("\n-----------------------------------------------------------------------------------\n");
        }
        printf("Number of elements in list = %d",list_count);
    }

    void insert_beginning (struct student a)
    {
       struct node* temp = NULL;
       temp = (struct node*)malloc(sizeof (struct node));
       temp->data = a;
       temp->next=NULL;

       if(head == NULL)
       {
           temp->next = head;
           head=temp;
           tail=temp;
       }
       else
       {
           temp->next = head;
           head=temp;
       }
       list_count++;
    }

    void insert_end (struct student a)
    {
        struct node* temp = NULL;
        temp = (struct node*)malloc(sizeof (struct node));
        temp->data = a;
        temp->next=NULL;

        if(head == NULL)
       {
            tail = temp;
            head = temp;
       }
       else
       {
            tail->next = temp;
            tail=temp;
       }
       list_count++;
    }

    void insert_middle (int l,struct student a)
    {
        if (l<1)
        {
            printf("\nWrong location enter a valid number\n");
        }
        else if(l > list_count+1)
            printf("\nWrong location total length of the list is %d\n",list_count);
        else
        {
            struct node* temp = NULL;
            temp = (struct node*)malloc(sizeof (struct node));
            temp->data = a;
            temp->next=NULL;

        if(l == 1)
        {
            insert_beginning (a);
        }
        else
        {
            struct node* pre = NULL;
            pre = head;
            int i;
            for (i=0; i<l-2 ;i++)
            {
                pre=pre->next;
            }
            struct node* aft = pre->next;
            temp->next=aft;
            pre->next=temp;
            list_count++;
        }
        }
    }
int choice,loc;
while(1)
{
    printf("\n\n**LIST MENU **\n");
    printf("1. insert beginning\n2. insert end\n3. insert middle\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:     read_data();
                    insert_beginning (a);
                    printlist();
                    break;

        case 2:     read_data();
                    insert_end (a);
                    printlist();
                    break;

        case 3:     printf("Enter the location of the student \n");
                    scanf("%d",&loc);
                    read_data();
                    insert_middle (loc,a);
                    printlist();
                    break;

        case 4:    return;

        default: printf("\nWrong selection!!! Please try again!!!\n");
    }
}
}
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
