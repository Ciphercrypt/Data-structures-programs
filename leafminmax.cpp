#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};


void Leafnodes(node *root)
{
	if (!root)
		return;
	
	if (!root->left && !root->right)
	{
		cout << root->data << endl; 
		return;
	}

	if (root->left)
	Leafnodes(root->left);
		
	if (root->right)
	Leafnodes(root->right);
} 

node* new_node(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
int findMax(node* root)
{
    if (root == NULL)
        return 0;
 
    int element = root->data;
    int left_element= findMax(root->left);
    int right_element= findMax(root->right);
    if (left_element> element)
        element = left_element;
    if (right_element> element)
        element = right_element;
    return element;
}

int main()
{
                                           ////////////////////////
                                           // OUR BINARY TREE     //                        
                                           //         40          //            
        node *root = new_node(40);          //       /   \         //
 root->left =new_node(20)  ;                //     20    70        //            
 root->right =new_node(70) ;                //    /   \            //       
 root->left->left = new_node(10) ;          //   10   40           //        
 root->left->right = new_node(40) ;         //      /  \           //    
 root->left->right->left = new_node(30) ;   //     30   50         //    
 root->left->right->right =new_node(50)  ;  ///////////////////////// 


    cout<<"The leaf nodes are:\n";
	Leafnodes(root);
	cout<<"The maximum element among the binary tree is:\n";
	cout<<findMax(root);
	return 0;
}

