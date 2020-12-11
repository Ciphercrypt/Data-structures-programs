#include <iostream>

using namespace std;


void SelectionSort(int array[], int array_size)
 {
	
	for (int i=0; i < array_size; i++) {
		int minimum = i;							
		
		for (int j = i+1; j < array_size; j++)
		{
			
			if (array[j] < array[minimum]) 
			{		
				minimum = j;						
			}
		}
		swap(array[i], array[minimum]);
	}
} 


int main() {
	int array[] = {2,7,4,1,3,0,9};
	cout<<"The array to be sorted is:\n"<<"[2,7,4,1,3,0,9]"<<endl;
	SelectionSort(array, 7);
	cout<<"Sorted array :\n";
	for (int i=0; i<7; i++) {
		cout << array[i] << " ";
	}

	return 0;
} 

