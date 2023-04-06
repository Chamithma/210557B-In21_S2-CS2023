#include <iostream>
#include <chrono>
using namespace std;

class Stack {
    int top;
  
public:
    int a[100]; // Maximum size of Stack
  
    Stack() { top = -1; }
    void push(int x);
    int pop();
    void display();
};
  
void Stack::push(int x)
{
    int length = sizeof(a) / sizeof(int);
    if(top>=length-1)
        cout<<"Stack Overflow"<<endl;
    else {
      a[++top] = x;
   }
}
  
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

int main(){
    int MyNumber;
    cout<<"Enter the array size number::";
    cin>>MyNumber;
    auto start = chrono::steady_clock::now();
    class Stack stack;
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
