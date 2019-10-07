#include <bits/stdc++.h>

using namespace std;

void MaxHeapify(int A[], int len, int i)
{
    int left = 2 * i;
    int right = (2 * i + 1);
    int large = i;
    if (left < len && A[left] > A[i])
    {
        large = left;
    }
    else
        large = i;

    if (right < len && A[right] > A[large])
    {
        large = right;
    }
    if (large != i)
    {
        swap(A[i], A[large]);
        MaxHeapify(A, len, large);
    }
}

void buildmaxheap(int A[], int n)
{
    int heapsize;
    heapsize = n;
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        MaxHeapify(A, n, i);
    }
}

void HeapSort(int A[], int n)
{
    buildmaxheap(A, n);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(A[0], A[i]);
        MaxHeapify(A, i, 0);
    }
}

int main()
{
    int n;
    cout << "Enter the length of array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter array elements(space separated):" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    HeapSort(arr, n);
    cout << "The sorted array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}