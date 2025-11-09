#include <iostream>
using namespace std;

#define SIZE 5

class Queue{
    string orders[SIZE];
    int front,rear;

    public:

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
            cout << "Queue is Full!";
            return;
        }

       if(front == -1) front = 0;
       rear++;
       orders[rear] = order;
       cout << order << " added successfully";
    }

    void dequeue(){
        if(isEmpty()){
            cout << "No orders to deliver!";
            return;
        }

        cout << orders[front] << " delivered";
        front++;
        if(front > rear){
            front = rear = -1;
        }
    }

    void peek(){
        if(isEmpty()){
            cout << "No pending orders!";
        }
        
        else{
            cout << "Next order to deliver: " << orders[front] << "\n";
        }
    }
};


int main(){
    Queue q;
    int choice;
    string order;

    do
    {
        
        cout << "Hotel Take Away Order System";
        cout << "\nMenu:\n";
        cout << "1. Add Order\n";
        cout << "2. Deliver Order\n";
        cout << "3. Show Next Order\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice){
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
            cout << "Exiting...";
            break;

            default:
            cout << "Invalid choice! Try again\n";
        }

    } while (choice != 4);

    return 0;
    
}
