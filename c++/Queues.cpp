#include <iostream>
using namespace std;

struct Queue {

    int arr[100],frontIndex,rearIndex,size,count;

    void init(int s){
        size = s;
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    bool isEmpty(){
        return count == 0;
    }

    bool isFull(){
        return count == size;
    }

    void enqueue(int x){
        if(isFull()){
            cout << "Cannot Enqueue!" << endl;
            return;
        }
        rearIndex = (rearIndex + 1) % size;
        arr[rearIndex] = x;
        count++;
        cout << x << " Enqueued " << endl;
    }

    int dequeue() {
        if(isEmpty()){
            cout << "Cannot Dequeue " << endl;
            return -1;
        }

        int removed = arr[frontIndex];
        frontIndex = (frontIndex + 1) % size;
        count--;
        return removed;
    }

    int getFront(){
        return arr[frontIndex];
    }

    int currentSize(){
        return count;
    }

};

int main(){
    int s;
    cout << "Enter the size of Queue: ";
    cin >> s;

    if(s <= 0 || s > 100){
        cout << "Invalid size!";
        return 0;
    }

    Queue q;
    q.init(s);

    int choice,value;

    while(true){
        cout << "\n====== Queue Menu ======\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Get Front\n";
        cout << "4. Size\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
            cout << "Enter a value to Enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;

            case 2: 
            value = q.dequeue();
            if(value != -1){
                cout << "Dequeued";
                break;
            }

            case 3: 
            value = q.getFront();
            if(value != -1){
                cout << "Front element: " << value << endl;
            }

            case 4:
            cout << "Current number of elements: " << q.currentSize() << endl;
            break;

            case 5:
            cout << "Exiting program.\n";
                return 0;

           default:
                cout << "Invalid choice! Please try again.\n";

        }
    }
}

