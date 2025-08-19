#include<iostream>
using namespace std;

typedef class node
{
    public:
        int data;
        struct node *next;
        
        node()
        {
            data = 0;
            next = NULL;
        }

        node(int value)
        {
            data = value;
            next = NULL;
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

            for(int icnt = 1; icnt <= iCount; icnt++)
            {
                cout<<"| "<<temp->data<<" |-> ";
                temp = temp -> next;
            }
            cout<<"\n";
        }

        int Count()
        {
            return iCount;
        }
};

class SinglyCL : public LinkedList
{
    private:
        PNODE Last;

    public:
         SinglyCL();
        ~SinglyCL();

        void InsertFirst(int ino);
        void InsertLast(int ino);
        void InsertAtPos(int ino, int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
};

SinglyCL:: SinglyCL()
{
    Last = NULL;
}

SinglyCL:: ~SinglyCL()
{}

void SinglyCL::InsertFirst(int ino)
{
    PNODE newn = NULL;
    newn = new NODE(ino);

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    
    Last->next = First;
    iCount++;
}
void SinglyCL::InsertLast(int ino)
{
    PNODE newn = NULL;
    newn = new NODE(ino);

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = Last->next;
    }
    
    Last->next = First;
    iCount++;
}


void SinglyCL::DeleteFirst()
{
    if (iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }
    iCount--;
}
void SinglyCL::DeleteLast()
{
    PNODE temp = First;

    if (iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        while (temp->next != First)
        {
            temp = temp->next;
        }

        delete Last;
        Last = temp;
        Last->next = First;
    }
    iCount--;
}

void SinglyCL::InsertAtPos(int ino, int ipos)
{
    if ((ipos < 1) || ipos > ipos+1)
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

        for ( int icnt = 1; icnt < ipos-1; icnt++)
        {
            temp = temp->next;
        }
        
        PNODE newn = new NODE(ino);

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
    
}

void SinglyCL::DeleteAtPos(int ipos)
{
    if ((ipos < 1) || ipos > ipos)
    {
        cout<<"Invalid Position \n";
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iCount+1)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = First;
        PNODE tempX = NULL;

        for ( int icnt = 1; icnt < ipos-1; icnt++)
        {
            temp = temp->next;
        }

        tempX = temp->next;
        temp->next = temp->next->next;

        delete tempX;

        iCount--;
    }
    
}

int main()
{
    SinglyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.InsertAtPos(90,2);

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.DeleteAtPos(2);
    
    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout<<"Number of elements are : "<<iRet<<"\n";

   
    return 0;
}