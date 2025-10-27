class Node6 {
    int data;
    Node6 next;

    Node6(int val) {
        data = val;
        next = null;
    }
}

class Add2NYmbers_LL {

    // Function to reverse the linked list
    static Node6 reverse(Node6 head) {
        Node6 prev = null, curr = head, next = null;
        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    static Node6 addTwoLists(Node6 head1, Node6 head2) {
      
        // Reverse both lists to start
        // from least significant digit
        head1 = reverse(head1);
        head2 = reverse(head2);

        Node6 sum = null;
        int carry = 0;

        // Traverse until both lists
        // and carry are processed
        while (head1 != null || head2 != null || carry > 0) {
            int newVal = carry;

            if (head1 != null) {
                newVal += head1.data;
                head1 = head1.next;
            }
            if (head2 != null) {
                newVal += head2.data;
                head2 = head2.next;
            }

            carry = newVal / 10;
            newVal %= 10;

            // Create new node and insert
            // at front of result list
            Node6 newNode = new Node6(newVal);
            newNode.next = sum;
            sum = newNode;
        }

        // Remove leading zeros if present
        while (sum != null && sum.data == 0) {
            sum = sum.next;
        }

        return (sum == null) ? new Node6(0) : sum;
    }
    
    static void printList(Node6 head) {
        Node6 curr = head;
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

        Node6 num1 = new Node6(1);
        num1.next = new Node6(2);
        num1.next.next = new Node6(3);

        Node6 num2 = new Node6(9);
        num2.next = new Node6(9);
        num2.next.next = new Node6(9);

        Node6 sum = addTwoLists(num1, num2);
        printList(sum);
    }
}