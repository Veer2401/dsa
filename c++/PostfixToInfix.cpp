#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    string arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }

    bool isFull() { return top == MAX - 1; }

    void push(string c) {
        if (isFull()) {
            cout << "Stack Overflow!";
        } else {
            arr[++top] = c;
        }
    }

    string pop() {
        if (isEmpty()) {
            cout << "Stack is Empty! Cannot pop elements.";
            return "";
        } else {
            return arr[top--];
        }
    }

    string peek() {
        if (isEmpty()) {
            cout << "Stack is Empty!";
            return "";
        } else {
            return arr[top];
        }
    }

    void printStack() {
        if (isEmpty()) {
            cout << "Stack is Empty!";
            return;
        } else {
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
        }
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToInfix(string &exp) {
    Stack st;
    string res;

    cout << "\nStep-by-step Conversion:\n";
    cout << "-------------------------------------------\n";
    cout << "Symbol\t\tStack (Top → Bottom)\n";
    cout << "-------------------------------------------\n";

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            string op(1, c);
            st.push(op);
        }

        
        else if (isOperator(c)) {
            string op2 = st.pop();
            string op1 = st.pop();
            string temp = "(" + op1 + c + op2 + ")";
            st.push(temp);
        }

        
        cout << " " << c << "\t\t";
        st.printStack();
        cout << "\n";
    }

    res = st.pop();
    cout << "-------------------------------------------\n";
    return res;
}

int main() {
    string exp;

    cout << "Enter a Postfix Expression: ";
    cin >> exp;

    string infix = postfixToInfix(exp);
    cout << "Infix Expression: " << infix << endl;

    return 0;
}
