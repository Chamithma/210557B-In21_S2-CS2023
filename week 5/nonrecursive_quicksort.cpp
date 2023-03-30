#include <iostream>
#include <chrono>
#include<stack>
using namespace std;

void swap(int arr[] , int pos1, int pos2){
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

int partition(int A[], int start, int end){
    int pivot_element = A[end];
    int i = start-1;
    int temp;
    for(int j = start; j<end; j++){
        if (A[j] <= pivot_element){
            i++;
            swap(A,i,j);

        }
    }
    swap(A,i+1,end);
    return (i+1);
}

void quickSort(int A[], int start, int end){
   stack<int> stack;
   stack.push(start);
   stack.push(end);

   while(!stack.empty()){
        int end = stack.top();
        stack.pop();
        int start = stack.top();
        stack.pop();

        int pivot = partition(A,start,end);

        if(pivot-1 > start){
            stack.push(start);
            stack.push(pivot-1);
        }
        if(pivot+1 < end){
            stack.push(pivot+1);
            stack.push(end);
        }
   }
}
    
int main(){
    int MyNumber;
    cout<<"Enter the array size number::";
    cin>>MyNumber;
    int Rand[MyNumber];
    for(int r= 0; r <MyNumber; r++)
    Rand[r]=rand()%10;
    int A[MyNumber];
    for(int r=0; r<MyNumber ; r++){
        A[r] = Rand[r];
    }
    auto start = chrono::steady_clock::now();
    quickSort(A,0,MyNumber-1);
    
    auto end = chrono::steady_clock::now();
	
	cout<<chrono::duration_cast<chrono::microseconds>(end-start).count()<< " microseconds" << endl;
	return 0;

}