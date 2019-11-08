#include <iostream>
void insertion_sort(int *arr, int size)
{
	for(int i=1;i<size;++i)
	{
		int j=i;
		int temp=arr[j];
		while ((j>0) && (arr[j-1]>temp))
		{
			arr[j]=arr[j-1];
			--j;
		}
		arr[j]=temp;
	}
}

int main()
{
	int array[]={5,4,3,1,2,3,1,1,3};
	int size = sizeof(array)/sizeof(array[0]);
	std::cout<<"before: ";
	for(int i = 0; i < size;++i)
		std::cout<<array[i]<<(i<size-1 ? ", ": "\n");
	insertion_sort(array, size);
	std::cout<<"after: ";
	for(int i = 0; i < size;++i)
		std::cout<<array[i]<<(i<size-1 ? ", ": "\n");
	return 0;
}
