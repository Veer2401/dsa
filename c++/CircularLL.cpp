#include <iostream>
using namespace std;

struct Node{
    int coef,exp;
    Node* next;
};

Node* createNode(int coef,int exp){
    Node* n = new Node;
    n->coef = coef;
    n->exp = exp;
    n->next = n;
    return n;
}

Node* insert(Node* head,int coef,int exp){
    Node* n = createNode(coef,exp);
    if(head == NULL){
        return n;
    }

    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    return head;
}

void display(Node* head){
    if(!head){
        cout << "Empty!\n";
        return;
    }

    Node* temp = head;
    do
    {
        cout << temp->coef << "x^" << temp->exp;
        temp = temp->next;
        if(temp != head){
            cout << " + ";
        }
    } while (temp != head);

    cout << endl;
}

Node* add(Node* p1,Node* p2){
    Node* res = NULL;
    Node* t1 = p1;
    Node* t2 = p2;

    do{
        if(t1->exp > t2->exp){
            res = insert(res,t1->coef,t1->exp);
            t1 = t1->next;
        }
        else if(t1->exp < t2->exp){
            res = insert(res,t2->coef,t2->exp);
            t2 = t2->next;
        }

        else{
            res = insert(res,t1->coef + t2->coef,t1->exp);
            t1 = t1->next;
            t2 = t2->next;
        }
    }while(t1 != p1 && t2 != p2);

    while(t1 != p1){
        res = insert(res,t1->coef,t1->exp);
        t1 = t1->next;
    }

    while(t2 != p2){
        res = insert(res,t2->coef,t2->exp);
        t2 = t2->next;
    }

    return res;
}

int main(){
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    int n,coef,exp;

    cout << "Enter number of terms in first polynomial: ";
    cin >> n;
    cout << "Enter coefficient and exponent: \n";
    for(int i=0;i<n;i++){
        cin >> coef >> exp;
        poly1 = insert(poly1,coef,exp);
    }

    cout << "Enter number of terms in second polynomial: ";
    cin >> n;
    cout << "Enter coefficient and exponent:\n";
    for(int i=0;i<n;i++){
        cin >> coef >> exp;
        poly2 = insert(poly2,coef,exp);
    }

    Node* sum = add(poly1,poly2);
    cout << "Resultant Polynomial: ";
    display(sum);

    return 0;
}