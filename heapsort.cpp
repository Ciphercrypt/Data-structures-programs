#include <iostream>
using namespace std;

void printheap(int * A, int r) {
	for (int i = 0; i < r; i++)
		cout << A[i] << ";";
}

void swap(int *A, int S, int E) {
	int temp = A[S];
	A[S] = A[E];
	A[E] = temp;
}
void heapmax(int *A, int i, int HeapSize) {
	int largest = i;
	if (2*i <= HeapSize && A[2*i] > A[i])
		largest = 2*i;
	if (2*i+1 <= HeapSize && A[2*i+1] > A[largest])
		largest = 2*i+1;
	if (largest != i) {
		swap(A, i, largest);
		heapmax(A, largest, HeapSize);
	}
}
void HeapSort(int *A, int S) {
	for (int i = S / 2; i >= 0; i--)
		heapmax(A, i, S);
	for (int i = S; i >= 1; i--) {
		swap(A, 0, i);
		S--;
		heapmax(A, 0, S);
	}
}

int main() 
{
	int arrsize;
    cout<<"Enter size of array to be sorted!\n";
	cin >> arrsize;
	int* num = new int[arrsize];
    cout<<"Enter elements of array:\n";
	for (int i = 0; i < arrsize; i++)
		cin >> num[i];

	HeapSort(num, arrsize - 1);
	printheap(num, arrsize); 
	delete[] num;
	return 0;
}

