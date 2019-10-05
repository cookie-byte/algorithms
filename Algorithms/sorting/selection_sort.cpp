#include <iostream>
using namespace std;

void selectionSort(int A[], int low, int high)
{
	int i, j, min, temp;  
    for (i = low; i < high-1; i++)  
    {  
        min = i;  
        for (j = i+1; j < high; j++) 
        {
        	if (A[j] < A[min])  
            	min = j;  
        } 
        int temp = A[min];
        A[min] = A[i];
        A[i] = temp;
    }
    cout<<"Sorted Array in increasing order is : \n"; 
    for (int i = 0; i < high; i++)  
        cout << A[i] << " ";  
    cout << endl;

}

int main()  
{  
    int A[] ={67, 23, 65, 10, 9,-12, 0};
    int n = sizeof(A) / sizeof(A[0]);
    selectionSort(A,0, n);   
    return 0;  
}  
