#include <iostream>
#include <chrono>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int n)
    {
        this->data = n;
        this->next = NULL;
    }
};

class Stack{
private:    
    Node *top;
public:
    Stack(){
        top = NULL;
    }
    void push(int x);
    int pop();
    void display();
    bool isEmpty();
    bool isFull();
    int stackTop();

};
// Function to push an element onto the stack
void Stack::push(int x){
Node *newNode = new Node(x);
    if(top == NULL)
    top = newNode;
    else{
        newNode -> next = top;
        top = newNode;
    }
}

// Function to pop an element onto the stack
int Stack::pop(){
    if(top == NULL){
        cout << "Stack is Empty" << endl;
    return -1;
    }
    else{
        int tempData = top -> data;
        Node *temp = top;
        top = top -> next;
        delete temp;
        return tempData;
    }
}
// Function to print the elements of the stack
void Stack::display(){
 if (top == NULL)
  cout<<"Stack is Empty";
 else
 {
  Node *temp=top;
  while(temp!=NULL)
  {   cout<<temp->data<<" ";
   temp=temp->next;
  }
  cout<<"\n";
 }
 
}
// Function to check if the stack is empty
bool Stack::isEmpty(){
    return top == NULL;
}

bool Stack::isFull(){
    return false;  //Linked list implementation of stack cannot be full
}

// Function to return the top of the stack
int Stack::stackTop(){
    if (!isEmpty())
            return top->data;
        else
            return -1;
}


int main(){
    int MyNumber;
    cout<<"Enter the array size number::";
    cin>>MyNumber;
    auto start = chrono::steady_clock::now();
    Stack stack;
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
