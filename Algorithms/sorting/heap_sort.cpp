// Heap Sort
#include <iostream>
using namespace std;

void Max_Heapify(int A[],int i,int heapsize){
    int l,r;
    int largest=i;
    l=2*i+1;
    r=2*i+2;
    if((l< heapsize) && (A[l]>A[largest])){
        largest =l;
    }
    if((r<heapsize) && (A[r]>A[largest])){
        largest=r;
    }
    if(largest!=i){
        int temp;
        temp=A[largest];
        A[largest]=A[i];
        A[i]=temp;
        Max_Heapify(A,largest,heapsize);
    }
}


void BuildMaxHeap(int A[], int heapsize){
    int length=heapsize;
    for(int i= (length/2)-1; i>=0; i--){
        Max_Heapify(A,i,heapsize);
    }
}


void heapSort(int A[], int low, int high){
    BuildMaxHeap(A,high);
    for(int i=high-1; i>low; i--){
        int temp;
        temp=A[i];
        A[i]=A[low];
        A[low]=temp;
        Max_Heapify(A,low,i);
    }
    cout<<"Sorted Array in increasing order is : \n"; 
    int i;  
    for (i = 0; i < high; i++)  
        cout << A[i] << " ";  
    cout << endl;
}

int main()  
{  
    int A[] ={67, 23, 65, 10, 9,-12, 0};
    int n = sizeof(A) / sizeof(A[0]);
    heapSort(A,0, n);   
    return 0;  
}  
