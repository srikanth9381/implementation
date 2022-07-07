/* C++ program to implement basic stack 
operations */
#include <bits/stdc++.h> 

using namespace std; 

#define MAX 1000 

class Stack { 
	int top; 

public: 
	int b[MAX]; // Maximum size of Stack 

	Stack() { top = -1; } 
	bool push(int y); 
	int pop(); 
	int peek(); 
	bool isEmpty(); 
}; 

bool Stack::push(int y) 
{ 
	if (top >= (MAX - 1)) { 
		cout << "Stack Overflow"; 
		return false; 
	} 
	else { 
		b[++top] = y; 
		cout << y << " pushed into stack\n"; 
		return true; 
	} 
} 

int Stack::pop() 
{ 
	if (top < 0) { 
		cout << "Stack Underflow"; 
		return 0; 
	} 
	else { 
		int y= a[top--]; 
		return y; 
	} 
} 
int Stack::peek() 
{ 
	if (top < 0) { 
		cout << "Stack is Empty"; 
		return 0; 
	} 
	else { 
		int y = b[top]; 
		return b; 
	} 
} 

bool Stack::isEmpty() 
{ 
	return (top < 0); 
} 

// Driver program to test above functions 
int main() 
{ 
	class Stack s; 
	s.push(30); 
	s.push(40); 
	s.push(50); 
	cout << s.pop() << " Popped from stack\n"; 

	return 0; 
} 
