import java.util.LinkedList;
import java.util.Queue;

// Node Structure
class Node1 {
    int data;
    Node1 left, right;

    Node1(int val) {
        data = val;
        left = null;
        right = null;
    }
}

class DepthOfTree {
    static int height(Node1 root) {
        if (root == null) return 0;

        // Initializing a queue to traverse
        // the tree level by level
        Queue<Node1> q = new LinkedList<>();
        q.add(root);
        int depth = 0;

        // Loop until the queue is empty
        while (!q.isEmpty()) {
            int levelSize = q.size();

            // Traverse all nodes at the current level
            for (int i = 0; i < levelSize; i++) {
                Node1 curr = q.poll();

                if (curr.left != null) q.add(curr.left);
                if (curr.right != null) q.add(curr.right);
            }

            // Increment height after traversing each level
            depth++;
        }
        return depth - 1;
    }

    public static void main(String[] args) {

        // Representation of the input tree:
        //     12
        //    /  \
        //   8   18
        //  / \
        // 5   11
        Node1 root = new Node1(12);
        root.left = new Node1(8);
        root.right = new Node1(18);
        root.left.left = new Node1(5);
        root.left.right = new Node1(11);

        System.out.println(height(root));
    }
}