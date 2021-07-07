#include <iostream>
using namespace std;

void printArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void bubbleSort(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int array[] = { 35, 1, 90, 45, 17, 83, 12, 3, 100, 15 };
	int size = sizeof(array) / sizeof(array[0]);

	cout << "Original array: ";
	printArray(array, size);

	bubbleSort(array, size);

	cout << "Sorted array: ";
	printArray(array, size);
}