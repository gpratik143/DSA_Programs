
#include <iostream>
using namespace std;

int size;

void heapify(int array[], int i)
{
	int large = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;
	if (left < size && array[left] > array[large])
		large = left;
	if (right < size && array[right] > array[large])
		large = right;
	if (large != i) {
		swap(array[i], array[large]);
		heapify(array, large);
	}
}

void build_heap(int array[])
{
	for (int i = size; i >= 0; i--) {
		heapify(array, i);
	}
}
int main()
{

	int array[] = {4,1,3,2,16,9,10,14,8,7};

	size = sizeof(array) / sizeof(array[0]);

	cout << "Sample Array : ";
	for (int i = 0; i < size; ++i)
		cout << array[i] << " ";
	cout <<endl;

	build_heap(array);

  	cout << "Heapify Array: ";
	for (int i = 0; i < size; ++i)
		cout << array[i] << " ";
	return 0;
}
//Heapify a single node takes O(log N) time complexity
//Building the entire Heap will take N heapify operations and the total time complexity will be O(N*logN).
