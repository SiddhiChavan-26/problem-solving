package invert;

import java.util.LinkedList;
import java.util.Queue;
import java.util.List;
import java.util.ArrayList;

// Node Structure
class Node {
    int data;
    Node left, right;

    Node(int x) {
        data = x;
        left = null;
        right = null;
    }
}

class InvertBinaryTree {

    static void mirror(Node root) {
        if (root == null)
            return;

        Queue<Node> queue = new LinkedList<>();
        queue.add(root);

        // Traverse the tree, level by level
        while (!queue.isEmpty()) {
            Node curr = queue.poll();

            // Swap the left and right subtree
            Node temp = curr.left;
            curr.left = curr.right;
            curr.right = temp;

            // Push the left and right node to the queue
            if (curr.left != null)
                queue.add(curr.left);
            if (curr.right != null)
                queue.add(curr.right);
        }
    }
    
    static int getHeight( Node root, int h ) {
        if( root == null ) return h-1;
        
        return Math.max(getHeight(root.left, h+1), getHeight(root.right, h+1));
    }
    
    static void levelOrder(Node root) {
        Queue<List<Object>> queue = new LinkedList<>();
        queue.offer(List.of(root, 0));
        
        int lastLevel = 0;
        
        // function to get the height of tree
        int height = getHeight(root, 0);
        
        // printing the level order of tree
        while( !queue.isEmpty()) {
            List<Object> top = queue.poll();
            
            Node node = (Node) top.get(0);
            int lvl = (int) top.get(1);
            
            if( lvl > lastLevel ) {
                System.out.println();
                lastLevel = lvl;
            }
            
            // all levels are printed
            if( lvl > height ) break;
            
            // printing null node
            System.out.print((node.data == -1 ? "N" : node.data) + " ");
            
            // null node has no children
            if( node.data == -1 ) continue;
            
            if( node.left == null ) queue.offer(List.of(new Node(-1), lvl+1));
            else queue.offer(List.of(node.left, lvl+1));
            
            if( node.right == null ) queue.offer(List.of(new Node(-1), lvl+1));
            else queue.offer(List.of(node.right, lvl+1));
        }
    }

    public static void main(String[] args) {
        // Input Tree:
        //       1
        //      / \
        //     2   3
        //    / \
        //   4   5
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        mirror(root);

        // Mirror Tree:
        //       1
        //      / \
        //     3   2
        //        / \
        //       5   4
        levelOrder(root);
    }
}
