class Node2 {
    int data;
    Node2 next;

    Node2(int x) {
        data = x;
        next = null;
    }
}

class MergeLinkedList {

    static Node2 sortedMerge(Node2 head1, Node2 head2) {

        // base cases
        if (head1 == null)
            return head2;
        if (head2 == null)
            return head1;

        // recursive merging based on smaller value
        if (head1.data <= head2.data) {
            head1.next = sortedMerge(head1.next, head2);
            return head1;
        }
        else {
            head2.next = sortedMerge(head1, head2.next);
            return head2;
        }
    }

    static void printList(Node2 curr) {
        while (curr != null) {
            System.out.print(curr.data);
            if (curr.next != null)
                System.out.print(" -> ");
            curr = curr.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {

        Node2 head1 = new Node2(5);
        head1.next = new Node2(10);
        head1.next.next = new Node2(15);
        head1.next.next.next = new Node2(40);

        Node2 head2 = new Node2(2);
        head2.next = new Node2(3);
        head2.next.next = new Node2(20);

        Node2 res = sortedMerge(head1, head2);
        printList(res);
    }
}