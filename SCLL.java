import java.util.*;

class programSCLL
{
    public static void main(String arg[])
    {
        SinglyCL obj = new SinglyCL();

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

    public Node(int value)
    {
        data = value;
        next = null;
    }
}

class SinglyCL
{
    private Node first;
    private Node last;
    private int size;

    public SinglyCL()
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
            System.out.print("|"+temp.data+"|->");
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
            last.next = first;
        }
        else
        {
            newn.next = first;
            first = newn;
            last.next = first;
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
            last.next = first;
        }
        else
        {
            last.next = newn;
            last = newn;
            last.next = first;
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
            Node temp = first;
            while(temp.next != last)
            {
                temp = temp.next;
            }
            temp.next = first;
            last = temp;
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
            size--;
        }
    }
}
