import javax.xml.crypto.Data;

// package AVL Trees;

public class AVLTrees {
    static class Node {
        int data;
        int height; // For Balanced Facor
        Node left;
        Node right;

        Node(int data) {
            this.data = data;
            height = 1;
        }
    }

    public static Node root;

    public static int height(Node root) {
        if (root == null) {
            return 0;
        }
        return root.height;
    }

    //right rotate subtree rotated with y
    public static Node rightRotate(Node y) {
        Node x = y.left;
        Node T2 = x.right;

        //Perform Rottion
        x.right = y;
        y.left  = T2;

        //Update height
        y.height = Math.max(height(y.left) , height(y.right)) + 1;
        x.height = Math.max(height(x.left) , height(x.right)) + 1;

        return x;
    }

    //left rotate subtree rotated with x
    public static Node leftRotate(Node x) {
        Node y = x.right;
        Node T2 = y.left;

        //Perform Rottion
        y.left = x;
        x.right = T2;

        //Update height
        x.height = Math.max(height(x.left) , height(x.right)) + 1;
        y.height = Math.max(height(y.left) , height(y.right)) + 1;

        return y;
    }

    //Get Balnaced Factor of Node
    public static int getbalance(Node root) {
        if (root == null) {
            return 0;
        }
        return height(root.left) - height(root.right);
    }

    public static Node insert(Node root, int key) {
        if (root == null) {
            return new Node(key);
        }
        if (key < root.data) {
            root.left = insert(root.left, key);
        } else if (key > root.data) {
            root.right = insert(root.right, key);
        } else {
            return root; // Duplicate Keys Not Allowed
        }

        // Update Root height
        root.height = 1 + Math.max(height(root.left), height(root.right));

        // Get root's Balance Factor
        int bf = getbalance(root);

        //Left Left Case
        if (bf > 1 && key < root.left.data) {
            return rightRotate(root);
        }

        //Right Right Case
        if (bf < -1 && key > root.right.data) {
            return leftRotate(root);
        }

        //Left Right Case
        if (bf > 1 && key > root.left.data) {
            root.left = leftRotate(root.left);
            return rightRotate(root);
        }

        //Right Left Case
        if (bf < -1 && key < root.right.data) {
            root.right = rightRotate(root.right);
            return leftRotate(root);
        }

        return root;
    }
    public static void preOrder(Node root) {
        if (root == null) {
            return;
        }

        System.out.print(root.data + " ");
        preOrder(root.left);
        preOrder(root.right);
    }

    public static void main(String[] args) {
        root = insert(root , 10);
        root = insert(root , 20);
        root = insert(root , 30);
        root = insert(root , 40);
        root = insert(root , 50);
        root = insert(root , 25);
        
        //    AVL  TREES
        //       30
        //      /  \
        //     20   40
        //    / \    \
        //   10 25   50   
        
        preOrder(root);
    }
}
