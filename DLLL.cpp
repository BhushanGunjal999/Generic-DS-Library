#include<iostream>
using namespace std;

typedef class node
{
    public:
        int data;
        struct node *next;
        struct node *prev;
    
        node()
        {
            data = 0;
            next = NULL;
            prev = NULL;
        }

        node(int value)
        {
            data = value;
            next = NULL;
            prev = NULL;
        }

}NODE, *PNODE;

class LinkedList
{
    public:
        PNODE First;
        int iCount;

        LinkedList()
        {
            First = NULL;
            iCount = 0;
        }

        virtual void InsertFirst(int ino) = 0;
        virtual void InsertLast(int ino) = 0;
        virtual void InsertAtPos(int ino, int ipos) = 0;

        virtual void DeleteFirst() = 0;
        virtual void DeleteLast() = 0;
        virtual void DeleteAtPos(int ipos) = 0;

        void Display()
        {
            PNODE temp = First;

            cout<<"Elements of Linked List are : "<<"\n";

            cout<<"NULL <=> "<<"";
            for(int icnt = 1; icnt <= iCount; icnt++)
            {
                cout<<"| "<<temp->data<<" |<=> ";
                temp = temp -> next;
            }
            cout<<"NULL"<<"\n";
        }

        int Count()
        {
            return iCount;
        }
};

class DoublyLL : public LinkedList
{
    public:
         DoublyLL();
        ~DoublyLL();

        void InsertFirst(int ino);
        void InsertLast(int ino);
        void InsertAtPos(int ino, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
};

DoublyLL:: DoublyLL()
{}

DoublyLL:: ~DoublyLL()
{}

void DoublyLL::InsertFirst(int ino)
{
    PNODE newn = new NODE(ino);

    if (iCount == 0)
    {
        First = newn;
    }
    else
    {
        First->prev = newn;
        newn->next = First;
        First = newn;
    }  
    iCount++;  
}

void DoublyLL::InsertLast(int ino)
{
    PNODE newn = new NODE(ino);

    if (iCount == 0)
    {
        First = newn;
    }
    else
    {
        PNODE temp = First;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->next = newn;
        newn->prev = temp;
    }  
    iCount++;  
}

void DoublyLL::DeleteFirst()
{
    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = NULL;   
    }
    iCount--;
}

void DoublyLL::DeleteLast()
{
    if (iCount == 0)
    {
        return;
    }
    else if (iCount == 1)
    {
        delete First;
        First = NULL;
    }
    else
    {
        PNODE temp = First;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

void DoublyLL::InsertAtPos(int ino, int ipos)
{
    if ((ipos < 1) || ipos > iCount+1)
    {
        cout<<"Invalid Position \n";
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(ino);
    }
    else if (ipos == iCount+1)
    {
        InsertLast(ino);
    }
    else
    {
        PNODE temp = First;

        for(int icnt = 1; icnt < ipos -1; icnt++)
        {
            temp = temp->next;
        }

        PNODE newn = new NODE(ino);

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

void DoublyLL::DeleteAtPos(int ipos)
{
    
    if ((ipos < 1) || ipos > iCount)
    {
        cout<<"Invalid Position \n";
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = First;

        for(int icnt = 1; icnt < ipos -1; icnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

int main()
{
    DoublyLL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    
    obj.Display();
    cout<<"Length of Linked list is : "<<obj.Count()<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(151);

    obj.Display();
    cout<<"Length of Linked list is : "<<obj.Count()<<"\n";

    obj.InsertAtPos(55,4);

    obj.Display();
    cout<<"Length of Linked list is : "<<obj.Count()<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();
    cout<<"Length of Linked list is : "<<obj.Count()<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();
    cout<<"Length of Linked list is : "<<obj.Count()<<"\n";

    return 0;
}