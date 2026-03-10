// Assignment 3


import java.util.Scanner;

class Node{
    String key;
    Node left,right,parent;
    int balanceFactor;

    Node(String key){
        this.key = key;
        left = right = null;
        parent = null;
        balanceFactor = 0;
    }
}

class AVLTree{

    Node root;

    int height(Node node){
        if(node == null)
            return 0;

        return 1 + Math.max(height(node.left), height(node.right));
    }

    void getBalance(Node node){
        if(node != null){
            node.balanceFactor = height(node.left) - height(node.right);
        }
    }

    Node rightRotate(Node y){
        Node x = y.left;
        Node T2 = x.right;

        x.right = y;
        y.left = T2;

        x.parent = y.parent;
        y.parent = x;

        if(T2 != null)
            T2.parent = y;

        getBalance(y);
        getBalance(x);

        return x;
    }

    Node leftRotate(Node x){
        Node y = x.right;
        Node T2 = y.left;

        y.left = x;
        x.right = T2;

        y.parent = x.parent;
        x.parent = y;

        if(T2 != null)
            T2.parent = x;

        getBalance(x);
        getBalance(y);

        return y;
    }

    Node leftrightRotate(Node node){
        node.left = leftRotate(node.left);
        return rightRotate(node);
    }

    Node rightleftRotate(Node node){
        node.right = rightRotate(node.right);
        return leftRotate(node);
    }

    Node insert(Node node, String key, Node parent){

        if(node == null){
            Node newNode = new Node(key);
            newNode.parent = parent;
            return newNode;
        }

        if(key.compareToIgnoreCase(node.key) < 0){
            node.left = insert(node.left, key, node);
        }
        else if(key.compareToIgnoreCase(node.key) > 0){
            node.right = insert(node.right, key, node);
        }
        else {
            return node;
        }

        getBalance(node);
        
        //LL rotate
        if(node.balanceFactor > 1 && key.compareToIgnoreCase(node.left.key) < 0)
            return rightRotate(node);

        //RR rotate
        if(node.balanceFactor < -1 && key.compareToIgnoreCase(node.right.key) > 0)
            return leftRotate(node);

        //LR rotate
        if(node.balanceFactor > 1 && key.compareToIgnoreCase(node.left.key) > 0)
            return leftrightRotate(node);

        //RL rotate
        if(node.balanceFactor < -1 && key.compareToIgnoreCase(node.right.key) < 0)
            return rightleftRotate(node);

        return node;
    }

    void inorder(Node node){
        if(node != null){
            inorder(node.left);
            System.out.println(node.key + " ");
            inorder(node.right);
        }
    }

    void displayBalance(Node node) {
        if (node != null) {
            displayBalance(node.left);
            System.out.println("Node: " + node.key + " | Balance Factor: " + node.balanceFactor);
            displayBalance(node.right);
        }
    }
}

public class AVL {

    public static void main(String[] args) {

        AVLTree tree = new AVLTree();
        Scanner sc = new Scanner(System.in);

        int choice;
        String month;

        do {
            System.out.println("\n--- AVL TREE MENU ---");
            System.out.println("1. Insert Month");
            System.out.println("2. Inorder Traversal");
            System.out.println("3. Display Balance Factor");
            System.out.println("4. Exit");
            System.out.print("Enter choice: ");

            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {

                case 1:
                    System.out.print("Enter month name: ");
                    month = sc.nextLine();

                    tree.root = tree.insert(tree.root, month, null);
                    System.out.println("Month inserted successfully.");
                    break;

                case 2:
                    System.out.print("Inorder Traversal: ");
                    tree.inorder(tree.root);
                    System.out.println();
                    break;

                case 3:
                    System.out.println("Balance Factor of each node:");
                    tree.displayBalance(tree.root);
                    break;

                case 4:
                    System.out.println("Program exited.");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 4);

        sc.close();
    }
}