#include <iostream>
using namespace std;

#define SIZE 10

class Queue{

    public:

    string orders[SIZE];
    int front,rear;

    Queue(){
        front = rear = -1;
    }

    bool isFull(){
        return rear == SIZE - 1;
    }

    bool isEmpty(){
        return (front == -1 || front > rear);
    }

    void enqueue(string order){
        if(isFull()){
            cout << "Cannot add orders!";
            return;
        }

        if(front == -1) front = 0;
        rear++;
        orders[rear] = order;
        cout << order << " added successfully!\n";
    }

    void dequeue(){
        if(isEmpty()){
            cout << "Cannot deliver orders!";
            return;
        }

        cout << orders[front] << " delivered successfully!\n";
        front++;
        if(front > rear){
            front = rear = -1;
        }
    }

    void peek(){
        if(isEmpty()){
            cout << "No orders to display!";
            return;
        }

        cout << "Next order to deliver: " << orders[front] << "\n";
    }

    void display(){
        if (isEmpty()) {
            cout << "No pending orders!\n\n";
            return;
        }

        cout << "Orders: ";
        for(int i = front;i<=rear;i++){
            cout << (i-front+1) << ". " << orders[i] << "\n";
        }
        cout << "\n";
    }

    void search(string order){
        if (isEmpty()) {
            cout << "No orders to search!\n\n";
            return;
        }

        bool found = false;

        for(int i = front;i<=rear;i++){
            if(orders[i] == order){
                cout << "Order: " << order << " was found.";
                found = true;
                break;
            }
        }

        if(!found){
            cout << "No order was found!";
        }
    }

    
};


int main(){
    Queue q;
    int ch;
    string order;

    do
    {
        cout << "==========HOTEL TAKE AWAY SYSTEM===========\n";
        cout << "1. Add order\n";
        cout << "2. Deliver order\n";
        cout << "3. Show next order\n";
        cout << "4. Display\n";
        cout << "5. Search\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> ch;
        cin.ignore();

        switch(ch){
            case 1:
            cout << "Enter order name: ";
            getline(cin,order);
            q.enqueue(order);
            break;

            case 2:
            q.dequeue();
            break;

            case 3:
            q.peek();
            break;

            case 4:
            q.display();
            break;

            case 5:
            cout << "Enter order to search: ";
            getline(cin,order);
            q.search(order);
            break;

            case 6:
            cout << "Thanks for ordering.";
            break;

            default:
            cout << "Enter correct choice!";
        }
    } while (ch != 6);
    
    return 0;
}
