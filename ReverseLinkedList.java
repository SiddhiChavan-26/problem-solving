import java.util.Stack;

class Node {
    int data;
    Node next;

    Node(int new_data) {
        data = new_data;
        next = null;
    }
}

class ReverseLinkedList{
    static Node reverseList(Node head) {
        Stack<Node> stack = new Stack<>();
        Node temp = head;

        // push all nodes into stack
        while (temp != null) {
            stack.push(temp);
            temp = temp.next;
        }

        // make the last node as new head of the linked list
        if (!stack.isEmpty()) {
            head = stack.pop();
            temp = head;

            // pop all the nodes and append to the linked list
            while (!stack.isEmpty()) {
                
                // append the top value of stack in list
                temp.next = stack.pop();

                temp = temp.next;
            }

            // update the next pointer of last node to null
            temp.next = null;
        }

        return head;
    }

    static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data);
            if (node.next != null)
                System.out.print(" -> ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);
        head.next.next.next.next = new Node(5);

        head = reverseList(head);
        printList(head);
    }
}