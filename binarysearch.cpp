#include <iostream>
using namespace std;

int main()
{
        int count1, i, arr[30], num, first, last, middle;
        cout<<"how many elements would you like to enter?:"; 
        cin>>count1;

        for (i=0; i<count1; i++)
        {
                cout<<"Enter number "<<(i+1)<<": "; 
                cin>>arr[i];
        }
        cout<<"Enter the number that you want to search:"; 
        cin>>num;
        first = 0;
        last = count1-1;
        middle = (first+last)/2;
        while (first <= last)
        {
           if(arr[middle] < num)
           {
                first = middle + 1;

           }
           else if(arr[middle] == num)
           {
                cout<<num<<" found in the array at the location "<<middle+1<<endl; 
                break; 
           } 
           else { 
                last = middle - 1; 
           } 
           middle = (first + last)/2; 
        } 
        

if(first > last)
        {
           cout<<num<<" nothing in the array";
        }
        return 0;
}

