class Node5 {
    int data;
    Node5 next;

    Node5(int x) {
        data = x;
        next = null;
    }
}

class ReverseLLInGroups {
    
    static Node5 reverseKGroup(Node5 head, int k) {
        if (head == null) {
            return head;
        }

        Node5 curr = head;
        Node5 newHead = null;
        Node5 tail = null;

        while (curr != null) {
            Node5 groupHead = curr;
            Node5 prev = null;
            Node5 nextNode = null;
            int count = 0;

            // Reverse the nodes in the current group
            while (curr != null && count < k) {
                nextNode = curr.next;
                curr.next = prev;
                prev = curr;
                curr = nextNode;
                count++;
            }

            // If newHead is null, set it to the
            // last node of the first group
            if (newHead == null) {
                newHead = prev;
            }

            // Connect the previous group to the 
            // current reversed group
            if (tail != null) {
                tail.next = prev;
            }

            // Move tail to the end of the
          	// reversed group
            tail = groupHead;
        }

        return newHead;
    }

    static void printList(Node5 head) {
        Node5 curr = head;
        while (curr != null) {
            System.out.print(curr.data);
            if(curr.next != null){
                System.out.print(" -> ");
            }
            curr = curr.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {

        Node5 head = new Node5(1);
        head.next = new Node5(2);
        head.next.next = new Node5(3);
        head.next.next.next = new Node5(4);
        head.next.next.next.next = new Node5(5);

        head = reverseKGroup(head, 3);
        printList(head);
    }
}