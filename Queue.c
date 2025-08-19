#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node
{
    int data;
    struct node *next;
} NODE, *PNODE;

// Queue structure
typedef struct queue
{
    PNODE First;
    int iCount;
} QUEUE;

// Function prototypes
void Initialize(QUEUE *q);
void Enqueue(QUEUE *q, int no);
int Dequeue(QUEUE *q);
void Display(QUEUE *q);
int Count(QUEUE *q);

void Initialize(QUEUE *q)
{
    q->First = NULL;
    q->iCount = 0;
}

void Enqueue(QUEUE *q, int no) // InsertLast
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if (q->First == NULL)
    {
        q->First = newn;
    }
    else
    {
        PNODE temp = q->First;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    q->iCount++;
}

int Dequeue(QUEUE *q) // DeleteFirst
{
    int Value = 0;

    if (q->iCount == 0)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else if (q->iCount == 1)
    {
        Value = q->First->data;
        free(q->First);
        q->First = NULL;
    }
    else
    {
        Value = q->First->data;
        PNODE temp = q->First;
        q->First = q->First->next;
        free(temp);
    }

    q->iCount--;

    return Value;
}

void Display(QUEUE *q)
{
    if (q->First == NULL)
    {
        printf("Nothing to display as Queue is empty\n");
        return;
    }

    printf("Elements of Queue are : \n");

    PNODE temp = q->First;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int Count(QUEUE *q)
{
    return q->iCount;
}

// Main function
int main()
{
    int iChoice = 1;
    int iValue = 0;
    int iRet = 0;

    QUEUE obj;
    Initialize(&obj);

    printf("-----------------------------------------------------\n");
    printf("Dynamic Implementation of Queue in C\n");
    printf("-----------------------------------------------------\n");

    while (iChoice != 0)
    {
        printf("-----------------------------------------------------\n");
        printf("1 : Insert element into Queue\n");
        printf("2 : Remove element from the Queue\n");
        printf("3 : Display elements from Queue\n");
        printf("4 : Count number of elements from Queue\n");
        printf("0 : Terminate the application\n");
        printf("-----------------------------------------------------\n");

        printf("Please enter the option : \n");
        scanf("%d", &iChoice);

        switch (iChoice)
        {
        case 1:
            printf("Enter the element that you want to insert\n");
            scanf("%d", &iValue);
            Enqueue(&obj, iValue);
            break;

        case 2:
            iRet = Dequeue(&obj);
            if (iRet != -1)
            {
                printf("Removed element from Queue is : %d\n", iRet);
            }
            break;

        case 3:
            Display(&obj);
            break;

        case 4:
            iRet = Count(&obj);
            printf("Number of elements are : %d\n", iRet);
            break;

        case 0:
            printf("Thank you for using the application\n");
            break;

        default:
            printf("Please enter valid option\n");
            break;
        } // End of switch
    }     // End of while

    return 0;
}
