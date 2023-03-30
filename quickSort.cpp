#include <iostream>
#include <chrono>
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
    if (start < end){
        int pivot = partition(A,start,end);
        quickSort(A,start,pivot-1);
        quickSort(A,pivot+1,end);
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