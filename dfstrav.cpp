#include <iostream>
#include<stack>
using namespace std;
# define MAX 50
class Node
{
public:
    int data;
    Node *next;
};

class stack
{
	Node *st[MAX];
	int top=-1;
	public:
		void push(Node *s)
		{
			if(top==MAX-1)
			{
				cout<<"\nOverflow";
			}
			else{
				st[++top]=s;	
			}
		}
		
		Node* pop()
		{
			if(top==-1)
			{
				cout<<"\nUnderflow";
				return 0;
			}
			else
			{
				return st[top--];
			}
	
		}
		
		int isfull()
		{
			if(top==MAX)
			return 1;
			
			else 
				return 0;
		}
		
		int isempty()
		{
			if(top==-1)
			return 1;
			else
			return 0;
		}
}s;

class queue
{
	Node *qu[MAX];
	int front=-1;
	int rear=-1;
	public:
		void enqueue(Node *s)
		{
			if(rear==MAX-1)
			{
				cout<<"\nOverflow";
			}
			else
			{
				++rear;
				qu[rear]=s;
			}
		}
		
		Node* dequeue()
		{
			if(rear == -1)
			{
				cout<<"\nUnderflow";
				return 0;
			}
			else
			{
				++front;
				return qu[front];
			}
	
		}
		
		int isfull()
		{
			if(rear==MAX)
			return 1;
			
			else 
				return 0;
		}
		
		int isempty()
		{
			if(rear == -1 || front == rear)
				return 1;
			else
				return 0;
		}
}q;

class List:public Node
{
	
	public:
    Node *listptr,*temp;
};

int visited[10];
int visited1[10];

class Graph
{
  public:
        int V;
        List* array;

        Graph(int n)
        {
            V = n;
            array = new List [V];
            for (int i = 0; i < V; ++i)
			{
	            array[i].listptr = NULL;
	            array[i].temp = NULL;
	            visited[i]=0; 
				visited1[i]=0;           
			}
                 
        }

       
        void create(int current, int nextnode)
        {
       
        	Node *newnode = new Node;  
            newnode->data = nextnode ;
            newnode->next = NULL;
            if(array[current].listptr==NULL)
            {
            array[current].listptr=array[current].temp=newnode;
            }
            else
            {
            array[current].temp->next=newnode;
              array[current].temp=array[current].temp->next;
            }
           
           

			newnode = new Node;
            newnode->data = current;
            newnode->next = NULL;

            if(array[nextnode].listptr==NULL)
            {
            array[nextnode].listptr=array[nextnode].temp=newnode;
            }
            else
            {
            array[nextnode].temp->next=newnode;
              array[nextnode].temp=array[nextnode].temp->next;
            }
            
         
        }
       
        void display()
        {
            for (int i=0;i<V;i++)
            {
                Node *temp1 = array[i].listptr;
                cout<<"\nlist of vertex "<<i<<" ";
                while (temp1)
                {
                    cout<<"-> "<<temp1->data;
                    temp1 = temp1->next;
                }
                cout<<"\n";
            }
        }
        
        void DFS(int i)
        {
        	
        	Node *v=array[i].listptr;
			visited[v->data]=1;
			cout<<" "<<v->data;
			s.push(v);
			while(s.isempty()!=1)
			{
				
				for(Node *temp1=array[v->data].listptr;temp1;temp1=temp1->next)
				{
					if(visited[temp1->data]!=1)
					{
						visited[temp1->data]=1;
						cout<<" "<<temp1->data;
						s.push(temp1);
						v=temp1;
						break;
					}
				}

				v=s.pop();
							
			}
			
			for(Node *temp1=array[v->data].listptr;temp1;temp1=temp1->next)
				{
					if(visited[temp1->data]!=1)
					{
						visited[temp1->data]=1;
						cout<<" "<<temp1->data;
						s.push(temp1);
						v=temp1;
						break;
					}
				}
			
		}
		
		

	
		
};

int main()
{
    int s,r;
	char ch;
    Graph g(5);
    int c;
    
    while (1)
    {
    	cout << "\n1. Create Graph\n2. DFS\nEnter your choice : ";
    	cin>>c;
    	
    	switch (c)
    	{
    		case 1 :
    			cout<<"\nCreate Adjacency Linked list\n";
			    do
			    {
			    	cout<<"\nStarting node : ";
			   		cin>>s;
			  		 cout<<"\nConnection : ";
			   		cin>>r;
			  		 g.create(s,r);
			   		
			   		cout<<"\nDo you want to continue?(Y/N) :: ";
					cin>>ch;
			   
				}while(ch=='y'||ch=='Y');
				g.display();
				break;
				
		
				
			case 3 :
				cout << "\nBFS";
				g.DFS(1);
				break;
		

			default:
				cout << "\nEnter right choice!!";
				break;
		}
	}
return 0;
}

