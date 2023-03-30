#include <bits/stdc++.h>
#include<iostream>
#include <iomanip>
#include <ios>
using namespace std;
 
int binarySearch(float A[], float item, int low, int high)
{
    if (low >= high) {
        return (item > A[low]) ? (low + 1) : low;
    }
 
    int mid = (low + high) / 2;
 
    if (item == A[mid])
        return mid + 1;
 
    if (item > A[mid])
        return binarySearch(A, item, mid + 1, high);
 
    return binarySearch(A, item, low, mid - 1);
}

void runningMedian(float A[], int n)
{
    int i, j, pos;
    float num;
    int count = 1;
 
    cout << "Median after adding the element 1" << "- " <<A[0] << "\n";
 
    for (i = 1; i < n; i++) {
        double median;
        j = i - 1;
        num = A[i];
 
        pos = binarySearch(A, num, 0, j);
 
        while (j >= pos) {
            A[j + 1] = A[j];
            j--;
        }
 
        A[j + 1] = num;
        count++;
 
        if (count % 2 != 0) {
            median = A[count / 2];
        }
        else {
            median = (A[(count / 2) - 1] + A[count / 2])/ 2;
        }
        cout << "Median after adding element "<< i+1 << "- "<< median << "\n";
    }
}

int main()
{int MyNumber;
    cout<<"Enter the array size number::";
    cin>>MyNumber;
    int Rand[MyNumber];
    for(int r= 0; r <MyNumber; r++)
    Rand[r]=rand()%10;
    float A[MyNumber];
    for(int r=0; r<MyNumber ; r++){
        A[r] = Rand[r];
    }
    cout << "elemenets of the array: ";
    for (int i=0;i<MyNumber;i++){
        cout << A[i] <<" ";
    }
    cout << endl;
    cout << fixed <<setprecision(1);
    runningMedian(A, MyNumber);
 
    return 0;
}