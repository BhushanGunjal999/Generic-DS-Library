import java.util.Scanner;

// Node class
class Node {
    int data;
    Node next;

    Node(int value) {
        data = value;
        next = null;
    }
}

// Queue class
class Queue {
    private Node first;
    private int count;

    public Queue() {
        first = null;
        count = 0;
    }

    // InsertLast
    public void enqueue(int no) {
        Node newn = new Node(no);

        if (first == null) {
            first = newn;
        } else {
            Node temp = first;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newn;
        }
        count++;
    }

    // DeleteFirst
    public int dequeue() {
        int value = 0;

        if (count == 0) {
            System.out.println("Queue is empty");
            return -1;
        } else if (count == 1) {
            value = first.data;
            first = null;
        } else {
            value = first.data;
            Node temp = first;
            first = first.next;
            temp = null;  // GC will clean up
        }

        count--;
        return value;
    }

    public void display() {
        if (first == null) {
            System.out.println("Nothing to display as Queue is empty");
            return;
        }

        System.out.println("Elements of Queue are : ");
        Node temp = first;
        while (temp != null) {
            System.out.println(temp.data);
            temp = temp.next;
        }
    }

    public int count() {
        return count;
    }
}

// Main class
public class QueueDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int iChoice = 1;
        int iValue = 0;
        int iRet = 0;

        Queue obj = new Queue();

        System.out.println("-----------------------------------------------------");
        System.out.println("Dynamic Implementation of Queue in Java");
        System.out.println("-----------------------------------------------------");

        while (iChoice != 0) {
            System.out.println("-----------------------------------------------------");
            System.out.println("1 : Insert element into Queue");
            System.out.println("2 : Remove element from the Queue");
            System.out.println("3 : Display elements from Queue");
            System.out.println("4 : Count number of elements from Queue");
            System.out.println("0 : Terminate the application");
            System.out.println("-----------------------------------------------------");

            System.out.print("Please enter the option : ");
            iChoice = sc.nextInt();

            switch (iChoice) {
                case 1:
                    System.out.print("Enter the element that you want to insert: ");
                    iValue = sc.nextInt();
                    obj.enqueue(iValue);
                    break;

                case 2:
                    iRet = obj.dequeue();
                    if (iRet != -1) {
                        System.out.println("Removed element from Queue is : " + iRet);
                    }
                    break;

                case 3:
                    obj.display();
                    break;

                case 4:
                    iRet = obj.count();
                    System.out.println("Number of elements are : " + iRet);
                    break;

                case 0:
                    System.out.println("Thank you for using the application");
                    break;

                default:
                    System.out.println("Please enter valid option");
                    break;
            }
        }

        sc.close();
    }
}
