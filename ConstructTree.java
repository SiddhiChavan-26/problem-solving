package construct;

import java.util.LinkedList;
import java.util.Queue;
import java.util.List;
import java.util.HashMap;
import java.util.Map;
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

class ConstructTree{
	
    // Recursive function to build the binary tree.
    static Node buildTreeRecur(Map<Integer, Integer> mp, int[] preorder, 
                               int[] preIndex, int left, int right) {

        // For empty inorder array, return null
        if (left > right)
            return null;

        int rootVal = preorder[preIndex[0]];
        preIndex[0]++;

        Node root = new Node(rootVal);

        int index = mp.get(rootVal);

        // Recursively create the left and right subtree.
        root.left = buildTreeRecur(mp, preorder, preIndex, left, index - 1);
        root.right = buildTreeRecur(mp, preorder, preIndex, index + 1, right);

        return root;
    }

    // Function to construct tree from its inorder and preorder traversals
    static Node buildTree(int[] inorder, int[] preorder) {

        // Hash map that stores index of a root element in inorder array
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < inorder.length; i++)
            mp.put(inorder[i], i);

        int[] preIndex = {0};
        return buildTreeRecur(mp, preorder, preIndex, 0, inorder.length - 1);
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
        int[] inorder = {3, 1, 4, 0, 5, 2};
        int[] preorder = {0, 1, 3, 4, 2, 5};
        Node root = buildTree(inorder, preorder);

        levelOrder(root);
    }
}