#include <iostream>

void merge(int *arr, int begin, int mid, int end, int size)
{
	int temp[size];
	int begin1 = begin, end1 = mid;
	int begin2 = mid+1, end2 = end;

	int i = begin1;
	while((begin1 <= end1) && (begin2 <= end2))
	{
		if(arr[begin1]<arr[begin2])
		{
			temp[i] = arr[begin1];
			++begin1;
		} else
		{
			temp[i]=arr[begin2];
			++begin2;
		}
		++i;
	}
	while(begin1 <= end1)
	{
		temp[i] = arr[begin1];
		++begin1;
		++i;
	}
	while(begin2 <= end2)
	{
		temp[i] = arr[begin2];
		++begin2;
		++i;
	}
	for(i = begin; i <= end; ++i)
	{
		arr[i] = temp[i];
	}
}

void merge_sort_func(int *arr, int begin, int end, int size)
{
	if(begin < end)
	{
		int mid = (begin+end) / 2;
		merge_sort_func(arr, begin, mid, size);
		merge_sort_func(arr, mid+1, end, size);
		merge(arr, begin, mid, end, size);
	}
}
void merge_sort(int *arr, int size)
{
	merge_sort_func(arr, 0, size -1, size);
}
int main()
{
	int array[]={5,4,3,1,2,3,1,1,3};
	int size = sizeof(array)/sizeof(array[0]);
	std::cout<<"before: ";
	for(int i = 0; i < size;++i)
		std::cout<<array[i]<<(i<size-1 ? ", ": "\n");
	merge_sort(array, size);
	std::cout<<"after: ";
	for(int i = 0; i < size;++i)
		std::cout<<array[i]<<(i<size-1 ? ", ": "\n");
	return 0;
}
