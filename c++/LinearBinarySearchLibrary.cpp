#include <iostream>
using namespace std;

class Book{
    public:
    int id;
    string title,author;

};

void linearSearch(Book books[],int n,string author){
    bool found = false;
    for(int i=0;i<n;i++){
        if(books[i].author == author){
            cout << "Book found!" << endl;
            cout << books[i].id << ", " << books[i].title << ", " << books[i].author << endl;
            found = true;
        }
    }
    if(!found){
        cout << "Book was not found!";
    }
}

void sortBooks(Book books[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(books[j].id > books[j+1].id){
                swap(books[j],books[j+1]);
            }
        }
    }
}

int binarySearch(Book books[],int n,int id){
    int low = 0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(books[mid].id == id){
            return mid;
        }
        else if(books[mid].id < id){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return -1;
}

int main(){
    int n;

    cout << "Enter number of books: ";
    cin >> n;

    Book books[n];

    cout << "Enter the book details: " << endl;
    for(int i=0;i<n;i++){
        cout << "ID: ";
        cin >> books[i].id;
        cout << "Title: ";
        cin >> books[i].title;
        cout << "Author: ";
        cin >> books[i].author;
    }

    int choice;
    string author;
    int id,index;

    do
    {
        cout << "===BOOK MANAGE===";
        cout << "1. Search by author\n";
        cout << "2. Search by ID\n";
        cout << "3. Exit";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
            cout << "Enter author name to search: ";
            cin >> author;
            linearSearch(books,n,author);
            break;

            case 2:
            cout << "Enter ID to search: ";
            cin >> id;

            sortBooks(books,n);
            index = binarySearch(books,n,id);
            if(index != -1){
                cout << "Book found!" << endl;
                cout << "ID: " << books[index].id << endl;
                cout << "Title: " << books[index].title << endl;
                cout << "Author: " << books[index].author << endl;
            }
            else{
                cout << "Book not found!";
            }

        }
    } while (choice != 3);
    return 0;
}
