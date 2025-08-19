import java.util.*;

class programDCLL
{
    public static void main(String arg[])
    {
        DoublyCL obj = new DoublyCL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

        obj.InsertAtPos(55,4);
        obj.Display();

        System.out.println("Number of elements are : "+obj.Count()); 

        obj.DeleteAtPos(4);

        obj.Display();

        System.out.println("Number of elements are : "+obj.Count()); 

        obj.DeleteFirst();               
        obj.DeleteLast();

        obj.Display();

        System.out.println("Number of elements are : "+obj.Count()); 

    }
}

class Node
{
    public int data;
    public Node next;
    public Node prev;

    public Node(int value)
    {
        data = value;
        next = null;
        prev = null;
    }
}

class DoublyCL
{
    private Node first;
    private Node last;
    private int size;

    public DoublyCL()
    {
        first = null;
        last = null;
        size = 0;
    }

    public void Display()
    {
        if(first == null)
        {
            return;
        }

        Node temp = first;
        do
        {
            System.out.print("|"+temp.data+"|<->");
            temp = temp.next;
        }while(temp != first);
        System.out.println();
    }

    public int Count()
    {
        return size;
    }

    public void InsertFirst(int no)
    {
        Node newn = new Node(no);

        if(first == null)
        {
            first = newn;
            last = newn;
            first.next = first;
            first.prev = first;
        }
        else
        {
            newn.next = first;
            newn.prev = last;
            first.prev = newn;
            last.next = newn;
            first = newn;
        }
        size++;
    }

    public void InsertLast(int no)
    {
        Node newn = new Node(no);

        if(first == null)
        {
            first = newn;
            last = newn;
            first.next = first;
            first.prev = first;
        }
        else
        {
            newn.prev = last;
            newn.next = first;
            last.next = newn;
            first.prev = newn;
            last = newn;
        }
        size++;
    }

    public void InsertAtPos(int no, int pos)
    {
        if((pos < 1) || (pos > size+1))
        {
            return;
        }

        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == size+1)
        {
            InsertLast(no);
        }
        else
        {
            Node newn = new Node(no);
            Node temp = first;

            for(int i=1; i<pos-1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            newn.prev = temp;
            temp.next.prev = newn;
            temp.next = newn;
            size++;
        }
    }

    public void DeleteFirst()
    {
        if(first == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
            first.prev = last;
            last.next = first;
        }
        size--;
    }

    public void DeleteLast()
    {
        if(first == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            last = last.prev;
            last.next = first;
            first.prev = last;
        }
        size--;
    }

    public void DeleteAtPos(int pos)
    {
        if((pos < 1) || (pos > size))
        {
            return;
        }

        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == size)
        {
            DeleteLast();
        }
        else
        {
            Node temp = first;

            for(int i=1; i<pos-1; i++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            temp.next.prev = temp;
            size--;
        }
    }
}
