#include <iostream>
using namespace std;

#define SIZE 10

class Queue{

    private:
    int front,rear;
    string orders[SIZE];

    public:
    Queue(){
        front = -1;
        rear = -1;
    }

    bool isFull(){
        return (rear == SIZE - 1);
    }

    bool isEmpty(){
        return (front == -1 || front > rear);
    }

    void enqueue(string order){
        if(isFull()){
            cout << "Cannot Take Orders!";
            return;
        }

        if(front == -1) front = 0;
        rear++;
        orders[rear] = order;

    }

    void addMultipleOrders(int count){
        if(count <= 0){
            cout << "Invalid Order Number!";
            return;
        }

        for(int i=0;i<count;i++){
            if(isFull()){
                cout << "Cannot add orders!";
                break;
            }

            string order;
            cout << "Enter order " << i + 1 << ": ";
            getline(cin,order);
            enqueue(order);
            cout << "Order " << order << "added successfully!";
        }
    }

    string dequeue(){
        if(isEmpty()){
            cout << "Cannot Deliver orders!";
            return "";
        }
        
        string deliveredOrder = orders[front];
        front++;

        if(front > rear){
            front = rear = -1;
        }

        return deliveredOrder;
    }

    void deliverSingleOrder(){
        string order = dequeue();
        if(order != ""){
            cout << "Order " << order << "delivered successfully!";
        }
    }

    void deliverMultipleOrders(int count){
        if(count <= 0){
            cout << "Cannot deliver orders!";
        }

        for(int i=0;i<count;i++){
            string order = dequeue();
            if(order == ""){
                break;
            }

            cout << "Order " << order << " delivered successfully!";
        }
    }

    void peek(){
        if(isEmpty()){
            cout << "No orders to deliver!";
        }
        else{
            cout << "Next order to deliver " << orders[front] << endl;
        }
    }

    void display(){
        if (isEmpty()) {
            cout << "No orders in the queue.\n";
            return;
        }

        cout << "Current orders in the Queue " << endl;
        for(int i=front;i<=rear;i++){
            cout << (i-front+1) << ". " << orders[i] << endl;
        } 
    }
};

int main(){
    Queue q;
    int choice,count;
    string order;

    cout << "--------------MC DONALD'S------------\n";

    do{
        cout << "\nMenu:\n";
        cout << "1. Add Single Order\n";
        cout << "2. Add Multiple Orders\n";
        cout << "3. Deliver Single Order\n";
        cout << "4. Deliver Multiple Orders\n";
        cout << "5. Show Next Order (Peek)\n";
        cout << "6. Display All Orders\n";
        cout << "7. Check if Queue is Full\n";
        cout << "8. Check if Queue is Empty\n";
        cout << "9. Exit\n";
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
            cout << "How many orders you want to add? ";
            cin >> count;
            cin.ignore();
            q.addMultipleOrders(count);

            case 3:
            q.deliverSingleOrder();
            break;

            case 4:
            cout << "How many orders you want to deliver?";
            cin >> count;
            cin.ignore();
            q.deliverMultipleOrders(count);
            break;

            case 5:
            q.peek();
            break;

            case 6:
            q.display();
            break;

            case 7:
            cout << (q.isFull() ? "Queue is FULL.\n" : "Queue is NOT full.\n");
            break;

            case 8:
            cout << (q.isEmpty() ? "Queue is EMPTY.\n" : "Queue is NOT empty.\n");
            break;

            case 9:
            cout << "Exiting system... Thank you!\n";
            break;

            default:
            cout << "Invalid choice! Try again.\n";

        }

    }while(choice != 9);

    return 0;
}
