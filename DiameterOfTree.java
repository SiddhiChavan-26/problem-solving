package dia;
//Node Structure
class Node {
 int data;
 Node left, right;

 Node(int x) {
     data = x;
     left = null;
     right = null;
 }
}

class DiameterOfTree {
 
 // Static variable to store maximum diameter
 static int maxDiameter = 0;

 // Recursive function to calculate height and update diameter
 static int diameterRecur(Node root) {
     if (root == null)
         return 0;

     // Find the height of left and right subtree
     int lHeight = diameterRecur(root.left);
     int rHeight = diameterRecur(root.right);

     // Update the global max diameter if this node gives a longer path
     if (lHeight + rHeight > maxDiameter)
         maxDiameter = lHeight + rHeight;

     // Return height of current subtree
     return 1 + Math.max(lHeight, rHeight);
 }

 // Function to get diameter of a binary tree
 static int diameter(Node root) {
     maxDiameter = 0; 
     diameterRecur(root);
     return maxDiameter;
 }

 public static void main(String[] args) {
     
     // Constructed binary tree:
     //          5
     //        /   \
     //       8     6
     //      / \   /
     //     3   7 9

     Node root = new Node(5);
     root.left = new Node(8);
     root.right = new Node(6);
     root.left.left = new Node(3);
     root.left.right = new Node(7);
     root.right.left = new Node(9);

     System.out.println(diameter(root));
 }
}