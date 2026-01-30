import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class Stack {
    int size = 50;
    Node[] stack = new Node[size];
    int top = -1;

    boolean isEmpty() {
        return top == -1;
    }

    boolean isFull() {
        return top == size - 1;
    }

    void push(Node n) {
        if (!isFull()) {
            stack[++top] = n;
        }
    }

    Node pop() {
        if (!isEmpty()) {
            return stack[top--];
        }
        return null;
    }
}

class BinaryTree {
    Node root;
    Scanner sc = new Scanner(System.in);
    int terminalNode = 0;

    public void insert(int data) {
        Node temp = root;

        while (true) {
            System.out.print("Enter Direction L or R from " + temp.data + ": ");
            char dir = sc.next().charAt(0);

            if (dir == 'L') {
                if (temp.left == null) {
                    temp.left = new Node(data);
                    System.out.println("Inserted at left of " + temp.data);
                    break;
                } else {
                    temp = temp.left;
                }
            } else if (dir == 'R') {
                if (temp.right == null) {
                    temp.right = new Node(data);
                    System.out.println("Inserted at right of " + temp.data);
                    break;
                } else {
                    temp = temp.right;
                }
            } else {
                System.out.println("Enter Correct Direction!");
            }
        }
    }

    // Recursive Traversals
    void inOrderRecursive(Node n) {
        if (n != null) {
            inOrderRecursive(n.left);
            System.out.print(n.data + " ");
            inOrderRecursive(n.right);
        }
    }

    void preOrderRecursive(Node n) {
        if (n != null) {
            System.out.print(n.data + " ");
            preOrderRecursive(n.left);
            preOrderRecursive(n.right);
        }
    }

    void postOrderRecursive(Node n) {
        if (n != null) {
            postOrderRecursive(n.left);
            postOrderRecursive(n.right);
            System.out.print(n.data + " ");
        }
    }

    // Non-Recursive Traversals
    void inOrderNonRecursive() {
        Stack s = new Stack();
        Node ptr = root;

        while (ptr != null || !s.isEmpty()) {
            while (ptr != null) {
                s.push(ptr);
                ptr = ptr.left;
            }

            ptr = s.pop();
            System.out.print(ptr.data + " ");
            ptr = ptr.right;
        }
    }

    void preOrderNonRecursive() {
        Stack s = new Stack();
        Node ptr = root;

        while (ptr != null || !s.isEmpty()) {
            while (ptr != null) {
                System.out.print(ptr.data + " ");
                s.push(ptr);
                ptr = ptr.left;
            }

            ptr = s.pop();
            ptr = ptr.right;
        }
    }

    void postOrderNonRecursive() {
        Stack s1 = new Stack();
        Stack s2 = new Stack();

        if (root == null)
            return;

        s1.push(root);

        while (!s1.isEmpty()) {
            Node temp = s1.pop();
            s2.push(temp);

            if (temp.left != null)
                s1.push(temp.left);

            if (temp.right != null)
                s1.push(temp.right);
        }

        while (!s2.isEmpty()) {
            System.out.print(s2.pop().data + " ");
        }
    }

    void terminalNodeCount(Node n) {
        if (n != null) {
            terminalNodeCount(n.left);

            if (n.left == null && n.right == null)
                terminalNode++;

            terminalNodeCount(n.right);
        }
    }
}

public class Tree {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        BinaryTree tree = new BinaryTree();
        boolean isTreeCreated = false;
        int choice;

        do {
            System.out.println("\n----- BINARY TREE MENU -----");
            System.out.println("1. Create Binary Tree");
            System.out.println("2. Inorder Traversal (Recursive)");
            System.out.println("3. Inorder Traversal (Non-Recursive)");
            System.out.println("4. Preorder Traversal (Recursive)");
            System.out.println("5. Preorder Traversal (Non-Recursive)");
            System.out.println("6. Postorder Traversal (Recursive)");
            System.out.println("7. Postorder Traversal (Non-Recursive)");
            System.out.println("8. Count Terminal Nodes");
            System.out.println("9. Exit");
            System.out.print("Enter your choice: ");

            choice = sc.nextInt();

            switch (choice) {

                case 1:
                    System.out.print("Enter number of nodes: ");
                    int n = sc.nextInt();

                    System.out.print("Enter root node value: ");
                    tree.root = new Node(sc.nextInt());

                    for (int i = 1; i < n; i++) {
                        System.out.print("Enter value for node: ");
                        tree.insert(sc.nextInt());
                    }

                    isTreeCreated = true;
                    System.out.println("Binary Tree Created Successfully!");
                    break;

                case 2:
                    if (!isTreeCreated) {
                        createTreePrompt();
                    } else {
                        System.out.print("Inorder Traversal (Recursive): ");
                        tree.inOrderRecursive(tree.root);
                        System.out.println();
                    }
                    break;

                case 3:
                    if (!isTreeCreated) {
                        createTreePrompt();
                    } else {
                        System.out.print("Inorder Traversal (Non-Recursive): ");
                        tree.inOrderNonRecursive();
                        System.out.println();
                    }
                    break;

                case 4:
                    if (!isTreeCreated) {
                        createTreePrompt();
                    } else {
                        System.out.print("Preorder Traversal (Recursive): ");
                        tree.preOrderRecursive(tree.root);
                        System.out.println();
                    }
                    break;

                case 5:
                    if (!isTreeCreated) {
                        createTreePrompt();
                    } else {
                        System.out.print("Preorder Traversal (Non-Recursive): ");
                        tree.preOrderNonRecursive();
                        System.out.println();
                    }
                    break;

                case 6:
                    if (!isTreeCreated) {
                        createTreePrompt();
                    } else {
                        System.out.print("Postorder Traversal (Recursive): ");
                        tree.postOrderRecursive(tree.root);
                        System.out.println();
                    }
                    break;

                case 7:
                    if (!isTreeCreated) {
                        createTreePrompt();
                    } else {
                        System.out.print("Postorder Traversal (Non-Recursive): ");
                        tree.postOrderNonRecursive();
                        System.out.println();
                    }
                    break;

                case 8:
                    if (!isTreeCreated) {
                        createTreePrompt();
                    } else {
                        tree.terminalNode = 0;
                        tree.terminalNodeCount(tree.root);
                        System.out.println("Number of terminal nodes: " + tree.terminalNode);
                    }
                    break;

                case 9:
                    System.out.println("Exiting program...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 9);
    }

    static void createTreePrompt() {
        System.out.println("Please create the tree first!");
    }
}
