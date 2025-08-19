#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node
{
    int data;
    struct node *next;
} NODE, *PNODE;

// Stack structure
typedef struct stack
{
    PNODE First;
    int iCount;
} STACK;

// Function prototypes
void Initialize(STACK *obj);
void Push(STACK *obj, int no);
int Pop(STACK *obj);
void Display(STACK *obj);
int Count(STACK *obj);

void Initialize(STACK *obj)
{
    obj->First = NULL;
    obj->iCount = 0;
}

void Push(STACK *obj, int no) // InsertLast
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    if (obj->First == NULL)
    {
        obj->First = newn;
    }
    else
    {
        PNODE temp = obj->First;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    obj->iCount++;
}

int Pop(STACK *obj) // DeleteLast
{
    int Value = 0;

    if (obj->iCount == 0)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else if (obj->iCount == 1)
    {
        Value = obj->First->data;
        free(obj->First);
        obj->First = NULL;
    }
    else
    {
        PNODE temp = obj->First;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        Value = temp->next->data;
        free(temp->next);
        temp->next = NULL;
    }

    obj->iCount--;

    return Value;
}

void Display(STACK *obj)
{
    if (obj->First == NULL)
    {
        printf("Nothing to display as Stack is empty\n");
        return;
    }

    printf("Elements of stack are : \n");

    PNODE temp = obj->First;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int Count(STACK *obj)
{
    return obj->iCount;
}

// Main function
int main()
{
    int iChoice = 1;
    int iValue = 0;
    int iRet = 0;

    STACK obj;
    Initialize(&obj);

    printf("-----------------------------------------------------\n");
    printf("Dynamic Implementation of Stack in C\n");
    printf("-----------------------------------------------------\n");

    while (iChoice != 0)
    {
        printf("-----------------------------------------------------\n");
        printf("1 : Push element into stack\n");
        printf("2 : Pop element from the stack\n");
        printf("3 : Display elements from stack\n");
        printf("4 : Count number of elements from stack\n");
        printf("0 : Terminate the application\n");
        printf("-----------------------------------------------------\n");

        printf("Please enter the option : \n");
        scanf("%d", &iChoice);

        switch (iChoice)
        {
        case 1:
            printf("Enter the element that you want to push\n");
            scanf("%d", &iValue);
            Push(&obj, iValue);
            break;

        case 2:
            iRet = Pop(&obj);
            if (iRet != -1)
            {
                printf("Poped element from stack is : %d\n", iRet);
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
