#include <iostream>

void bubble_sort(int *arr, int size)
{
	for(int i=1;i<size;++i)
		for(int j=size-1; j>=1; j--)
		{
			if (arr[j]<arr[j-1])
			{
				int temp=arr[j-1];
				arr[j-1]=arr[j];
				arr[j]=temp;
			}
		}
}

int main()
{
	int array[]={5,4,3,1,2,3,1,1,3};
	int size = sizeof(array)/sizeof(array[0]);
	std::cout<<"before: ";
	for(int i = 0; i < size;++i)
		std::cout<<array[i]<<(i<size-1 ? ", ": "\n");
	bubble_sort(array, size);
	std::cout<<"after: ";
	for(int i = 0; i < size;++i)
		std::cout<<array[i]<<(i<size-1 ? ", ": "\n");
	return 0;
}
