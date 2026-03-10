import java.util.Scanner;

class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        left = right = null;
    }
}

class BinarySearchTree {

    Node root;
    Scanner sc = new Scanner(System.in);

    void insert(int data) {
        Node newNode = new Node(data);

        if (root == null) {
            root = newNode;
            System.out.println("Inserted as root node.");
            return;
        }

        Node temp = root;
        Node parent = null;

        while (temp != null) {
            parent = temp;

            if (data < temp.data)
                temp = temp.left;

            else if (data > temp.data)
                temp = temp.right;

            else {
                System.out.println("Duplicate values not allowed.");
                return;
            }
        }

        if (data < parent.data)
            parent.left = newNode;
        else
            parent.right = newNode;

        System.out.println("Element inserted successfully.");
    }

    void delete(int key) {

        Node parent = null;
        Node curr = root;

        while (curr != null && curr.data != key) {
            parent = curr;

            if (key < curr.data)
                curr = curr.left;
            else
                curr = curr.right;
        }

        if (curr == null) {
            System.out.println("Element not found.");
            return;
        }

        if (curr.left == null || curr.right == null) {

            Node child = (curr.left != null) ? curr.left : curr.right;

            if (curr == root)
                root = child;

            else if (curr == parent.left)
                parent.left = child;

            else
                parent.right = child;
        }

        else {

            Node succParent = curr;
            Node succ = curr.right;

            while (succ.left != null) {
                succParent = succ;
                succ = succ.left;
            }

            curr.data = succ.data;

            if (succParent.left == succ)
                succParent.left = succ.right;
            else
                succParent.right = succ.right;
        }

        System.out.println("Element deleted successfully.");
    }

    void search(int key) {

        Node temp = root;

        while (temp != null) {

            if (key == temp.data) {
                System.out.println("Element found in BST.");
                return;
            }

            else if (key < temp.data)
                temp = temp.left;

            else
                temp = temp.right;
        }

        System.out.println("Element not found in BST.");
    }

    void findMin() {

        if (root == null) {
            System.out.println("BST is empty.");
            return;
        }

        Node temp = root;

        while (temp.left != null)
            temp = temp.left;

        System.out.println("Minimum element: " + temp.data);
    }

    void findMax() {

        if (root == null) {
            System.out.println("BST is empty.");
            return;
        }

        Node temp = root;

        while (temp.right != null)
            temp = temp.right;

        System.out.println("Maximum element: " + temp.data);
    }

    void display() {

        if (root == null) {
            System.out.println("BST is empty.");
            return;
        }

        Node[] stack = new Node[100];
        int top = -1;
        Node curr = root;

        System.out.print("BST (Inorder): ");

        while (curr != null || top != -1) {

            while (curr != null) {
                stack[++top] = curr;
                curr = curr.left;
            }

            curr = stack[top--];
            System.out.print(curr.data + " ");

            curr = curr.right;
        }

        System.out.println();
    }
}

public class BST {

    public static void main(String[] args) {

        BinarySearchTree bst = new BinarySearchTree();
        Scanner sc = new Scanner(System.in);

        int choice, value;

        do {

            System.out.println("\n--- BST MENU ---");
            System.out.println("1. Insert");
            System.out.println("2. Delete");
            System.out.println("3. Search");
            System.out.println("4. Find Minimum");
            System.out.println("5. Find Maximum");
            System.out.println("6. Display");
            System.out.println("7. Exit");

            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {

                case 1:
                    System.out.print("Enter value to insert: ");
                    value = sc.nextInt();
                    bst.insert(value);
                    break;

                case 2:
                    System.out.print("Enter value to delete: ");
                    value = sc.nextInt();
                    bst.delete(value);
                    break;

                case 3:
                    System.out.print("Enter value to search: ");
                    value = sc.nextInt();
                    bst.search(value);
                    break;

                case 4:
                    bst.findMin();
                    break;

                case 5:
                    bst.findMax();
                    break;

                case 6:
                    bst.display();
                    break;

                case 7:
                    System.out.println("Program terminated.");
                    break;

                default:
                    System.out.println("Invalid choice.");
            }

        } while (choice != 7);
    }
}