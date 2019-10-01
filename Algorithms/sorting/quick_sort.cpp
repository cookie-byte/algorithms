#include <iostream>

void swap(int& a, int &b)
{
	int temp = a;
	a=b;
	b=temp;
}

void quick_sort_func(int *arr, int left, int right)
{
	if (left < right)
	{
		int m=left;
		for(int i=left+1;i<=right;++i)
			if(arr[i]<arr[left])
				swap(arr[++m],arr[i]);
		swap(arr[left],arr[m]);
		quick_sort_func(arr,left,m-1);
		quick_sort_func(arr,m+1,right);

	}
}

void quick_sort(int *arr, int size)
{
	quick_sort_func(arr,0,size-1);
}

int main()
{
	int array[]={5,4,3,1,2,3,1,1,3};
	int size = sizeof(array)/sizeof(array[0]);
	std::cout<<"before: ";
	for(int i = 0; i < size;++i)
		std::cout<<array[i]<<(i<size-1 ? ", ": "\n");
	quick_sort(array, size);
	std::cout<<"after: ";
	for(int i = 0; i < size;++i)
		std::cout<<array[i]<<(i<size-1 ? ", ": "\n");
	return 0;
}
