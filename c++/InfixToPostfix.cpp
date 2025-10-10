#include <iostream>
using namespace std;

#define MAX 100

class Stack{
	char arr[MAX];
	int top;
	
	public:
		Stack(){
			top = -1;
		}
		
		bool isEmpty(){
			return top == -1;
		}
		
		bool isFull(){
			return top == MAX - 1;
		}
		
		void push(char c){
			if(isFull()){
				cout << "Stack Overflow!";
			}
			else{
				arr[++top] = c;
			}
		}
		
		char pop(){
			if(isEmpty()){
				cout << "Stack is Empty! Cannot pop elements.";
				return '\0';
			}
			else{
				return arr[top--];
			}
		}
		
		char peek(){
			if(isEmpty()){
				cout << "Stack is Empty! Cannot pop elements.";
				return '\0';
			}
			else{
				return arr[top];
			}
		}
		
		void printStack(){
			if(isEmpty()){
				cout << "Stack is Empty!";
				return;
			}
			else{
				for(int i=0;i<=top;i++){
					cout << arr[i];
				}
			}
		}
};

int prec(char c){
	 if(c == '^'){
		return 3;
	}
	else if(c == '*' || c == '/'){
		return 2;
	}
	else if(c == '+' || c == '-'){
		return 1;
	}
	else{
		return -1;
	}
}

bool isRightAssociative(char c){
	return c == '^';
}

string infixToPostfix(string &s){
	Stack st;
	string res;
	
	cout << "\nStep-by-step Conversion:\n";
	cout << "--------------------------------\n";
    cout << "Symbol\tStack\t\tPostfix\n";
    cout << "--------------------------------\n";
    
    for(int i=0;s[i] != '\0'; i++){
    	char c = s[i];
    	
    	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
    		res += c;
		}
		
		else if(c == '('){
			st.push(c);
		}
		
		else if(c == ')'){
			while(!st.isEmpty() && st.peek() != '('){
				res += st.pop();
			} 
			
			if(!st.isEmpty()){
				st.pop();
			}
		}
		
		else{
			while(!st.isEmpty() && st.peek() != '(' &&
			(prec(st.peek()) > prec(c) || 
			(prec(st.peek()) == prec(c) && !isRightAssociative(c)))){
				res += st.pop();
			}
			st.push(c);
		}
		
		cout << " " << c << "\t";
		st.printStack();
		cout << "\t\t" << res << "\n";
	}
	
	while(!st.isEmpty()){
		res += st.pop();
	}
	
	cout << "------------------------------\n";
	return res;
	
}

int main(){
	string exp;
	
	cout << "Enter an expression: ";
	cin >> exp;

	string postFix = infixToPostfix(exp);
	cout << "PostFix Expression: " << postFix << endl;
	
	return 0;
}
