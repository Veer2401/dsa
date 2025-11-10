#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;

void insertNode(int x){
    Node* n = new Node();
    n->data = x;
    n->next = NULL;

    if(head == NULL){
        head = n;
    }
    else{
        Node* t = head;
        while(t->next != NULL){
            t = t->next;
        }
        t->next = n;
    }
    cout << "Inserted.\n";
}

void deleteNode(int x){
    Node *t = head, *p = NULL;
    
    if(head == NULL){
        cout << "List is Empty!";
    }

    if(t->data == x){
        head = t->next;
        delete t;
        cout << "Deleted\n";
        return;
    }

    while(t != NULL && t->data != x){
        p = t;
        t = t->next;
    }

    if(t == NULL){
        cout << "Not found!\n";
    }

    else{
        p->next = t->next;
        delete t;
        cout << "Deleted\n";
    }
}

void display(){
    Node* t = head;

    if(head == NULL){
        cout << "List is Empty!";
        return;
    }

        cout << "List: ";
        while(t != NULL){
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    
}

void searchNode(int x){
    Node* t = head;
    int pos = 1;
    while(t != NULL){
        if(t->data == x){
            cout << "Found at position " << pos << "\n";
            return;
        }
        t = t->next;
        pos++;
    }
    cout << "Not found!";
}

void reverseList(){
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    cout << "Reversed!\n";
}

void sortList(){
    for(Node* i = head; i != NULL; i = i->next){
        for(Node* j = i->next; j != NULL; j = j->next){
            if(i->data > j->data){
                swap(i->data , j->data);
            }
        }
    }

    cout << "Sorted!";
}

int main(){
    int ch,x;
    while(1){
        cout << "\n1.Insert  2.Delete  3.Display  4.Search\n";
        cout << "5.Reverse  6.Sort  7.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch(ch){
            case 1:
            cout << "Enter value: ";
            cin >> x;
            insertNode(x);
            break;

            case 2:
            cout << "Enter value to delete: ";
            cin >> x;
            deleteNode(x);
            break;

            case 3:
            display();
            break;

            case 4:
            cout << "Enter value to search: ";
            cin >> x;
            searchNode(x);
            break;

            case 5:
            reverseList();
            break;

            case 6:
            sortList();
            break;

            case 7:
            return 0;

            default:
            cout << "Enter correct choice!";
        }
    }
}