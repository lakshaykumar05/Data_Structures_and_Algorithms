package linkedList;


import java.util.Scanner;

public class reverse_linked_list {
    Node head;

    public static class Node {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    public void pushAtEnd(int d) {
        Node newNode = new Node(d);
        Node temp = head;
        if (temp == null) {
            head = newNode;
        } else {
            while (temp.next != null) {
                temp = temp.next;
            }

            temp.next = newNode;
        }
        newNode.next = null;
    }

        /* Iterative solution taking curr,next and prev node and pointing current node to prev node and
        changing position of curr, prev and next.
        Time Complexity - O(n)
        Space Complexity - O(1)
        */

    public void reverseLinkedListIteration() {
        Node prev = null;
        Node curr = head;
        Node next = null;
        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

     /* Recursive solution taking curr,next and prev node and pointing current node to prev node and
        changing position of curr, prev and next.
        Time Complexity - O(n)
        Space Complexity - O(n)
        */

    public Node reverseLinkedListRecursion(Node curr, Node prev, Node next) {

        if (curr == null)
            return prev;
        else {
            next = curr.next;
            curr.next = prev;
            return reverseLinkedListRecursion(next, curr, next);
        }
    }

    /* Can also be done using stack and array*/

    public void display() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        reverse_linked_list obj = new reverse_linked_list();
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            obj.pushAtEnd(in.nextInt());
        }
        obj.display();
        obj.reverseLinkedListIteration();
        obj.display();
        obj.head = obj.reverseLinkedListRecursion(obj.head, null, null);
        obj.display();
    }
}
