#include<iostream>
using namespace std;
int main()
{
    int n,num,c=0;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched\n";
    cin>>num;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==num)
        {
                  cout<<"ELEMENT FOUND\n";
        cout<<"Number of comparisons "<<i+1;
        c++;
        }


    }
    if(c==0)
    {
        cout<<"ELEMENT NOT FOUND\n";
    }
    return 0;
}

