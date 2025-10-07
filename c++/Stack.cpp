#include <iostream>
using namespace std;

class Stack {

private:
    int arr[100], top, maxSize = 100;

public:
    Stack(int size) {
        if (size > 100) {
            cout << "Size is large!";
            exit(0);
        } else {
            maxSize = size;
        }
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == maxSize - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "The stack is full! Cannot add elements" << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed to stack" << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot remove elements" << endl;
        } else {
            cout << arr[top--] << " removed from the stack" << endl;
        }
    }

    void peek(int position) {
        // position = 1 means the topmost element
        int index = top - position + 1;
        if (index < 0 || index > top) {
            cout << "Invalid position!" << endl;
        } else {
            cout << "Element at position " << position << " is: " << arr[index] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack contents: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter stack size (max 100): ";
    cin >> size;

    Stack s(size);
    int choice, value, pos;

    do {
        cout << "\nChoose an option:\n"
             << "1. Push\n"
             << "2. Pop\n"
             << "3. Display\n"
             << "4. Peek\n"
             << "5. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.display();
            break;

        case 4:
            cout << "Enter position to peek (1 = topmost): ";
            cin >> pos;
            s.peek(pos);
            break;

        case 5:
            cout << "Exit" << endl;
            return 0;  // Exit the program

        default:
            cout << "Invalid choice!" << endl;
        }
    } while (true);
}
