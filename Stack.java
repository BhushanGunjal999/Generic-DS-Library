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

// Stack class
class Stack {
    private Node first;
    private int count;

    public Stack() {
        first = null;
        count = 0;
    }

    public void push(int no) {    // InsertLast
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

    public int pop() {    // DeleteLast
        int value = 0;

        if (count == 0) {
            System.out.println("Stack is empty");
            return -1;
        } else if (count == 1) {
            value = first.data;
            first = null;
        } else {
            Node temp = first;
            while (temp.next.next != null) {
                temp = temp.next;
            }
            value = temp.next.data;
            temp.next = null;
        }

        count--;
        return value;
    }

    public void display() {
        if (first == null) {
            System.out.println("Nothing to display as Stack is empty");
            return;
        }

        System.out.println("Elements of stack are : ");
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
public class StackDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int iChoice = 1;
        int iValue = 0;
        int iRet = 0;

        Stack obj = new Stack();

        System.out.println("-----------------------------------------------------");
        System.out.println("Dynamic Implementation of Stack in Java");
        System.out.println("-----------------------------------------------------");

        while (iChoice != 0) {
            System.out.println("-----------------------------------------------------");
            System.out.println("1 : Push element into stack");
            System.out.println("2 : Pop element from the stack");
            System.out.println("3 : Display elements from stack");
            System.out.println("4 : Count number of elements from stack");
            System.out.println("0 : Terminate the application");
            System.out.println("-----------------------------------------------------");

            System.out.print("Please enter the option : ");
            iChoice = sc.nextInt();

            switch (iChoice) {
                case 1:
                    System.out.print("Enter the element that you want to push: ");
                    iValue = sc.nextInt();
                    obj.push(iValue);
                    break;

                case 2:
                    iRet = obj.pop();
                    if (iRet != -1) {
                        System.out.println("Popped element from stack is : " + iRet);
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
