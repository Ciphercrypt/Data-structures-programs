#include<iostream>
using namespace std;
int Top=-1;
int Stack[5];
void push()
{
    if(Top<5-1)
    {
        Top+=1;
        cout<<"Enter data\n";
        cin>>Stack[Top];
    }else{cout<<"your stack is full,i.e. Overflow\n";}
    
}
void pop()
{   if(Top!=-1){
    cout<<"The popped element is \n";
    cout<<Stack[Top];
    Top-=1;
}else{cout<<"Stack is empty ,i.e.Underflow\n";}
}


int main()
{
    int i;    
    cout<<"\nEnter the operation to perform on stack\n(1)push \n(2)pop\n(3)EXIT\n";
    cin>>i;
    
        

        main();
        

switch(i)
    {
        case 1:
        push();
        main();
        break;
        case 2:
        pop();
        main();
        break;
        case 3:
        break;
        default:
        cout<<"Enter the valid option\n ";
        main();
        break;
    }

    return 0;
    
}

