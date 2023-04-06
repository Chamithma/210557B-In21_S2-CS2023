#include <iostream>
#include <chrono>
using namespace std;

class Stack {
    int top; // index of the top element
    int* a; // pointer to the array
    int capacity; // maximum capacity of the stack

public:
    Stack(int size) { // constructor to initialize the stack
        capacity = size;
        a = new int[capacity];
        top = -1;
    }
    void push(int x);
    int pop();
    void display();
    bool isEmpty();
    bool isFull();
    int stackTop();

};

// Function to push an element onto the stack 
void Stack::push(int x)
{
    if(top>=capacity -1)
        cout<<"Stack Overflow"<<endl;
    else {
      a[++top] = x;
   }
}
// Function to pop an element onto the stack
int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
// Function to print the elements of the stack
void Stack::display()
{
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<a[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
}
// Function to check if the stack is empty
bool Stack::isEmpty()
{
    return (top < 0);
}
// Function to check if the stack is full
bool Stack::isFull(){
    return(top == capacity - 1);
}
// Function to return the top of the stack
int Stack::stackTop(){
    return(a[top]);
}



int main(){
    int MyNumber;
    cout<<"Enter the array size number::";
    cin>>MyNumber;
    auto start = chrono::steady_clock::now();
    class Stack stack(MyNumber);
    for(int r=0; r<MyNumber ; r++){
        stack.push(rand()%10);
    }
    stack.display();
    for(int r=0; r<5; r++){
        stack.pop();
    }
    for(int r=0; r<4 ; r++){
     stack.push(rand()%10);
    }
    stack.display();

    auto end = chrono::steady_clock::now();
	
	cout<<chrono::duration_cast<chrono::microseconds>(end-start).count()<< " microseconds" << endl;
	return 0;
}