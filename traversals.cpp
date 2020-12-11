#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void Preorder(struct Node* node)
{
    if (node == NULL) return;
    
    cout << node->data << " \n";
    
    Preorder(node->left);
    Preorder(node->right);
}

void Postorder(struct Node* node)
{
    if (node == NULL) return;
    
    Postorder(node->left);
    Postorder(node->right);
    
    cout << node->data << " \n";
}

void Inorder(struct Node* node)
{
    if (node == NULL) return;
    
    Inorder(node->left);
    
    cout << node->data << " \n";
    
    Inorder(node->right);
    
    
}

int main() {
    

                                           ////////////////////////
                                           // OUR BINARY TREE     //                        
                                           //         40          //            
struct Node *root = new Node(40);          //       /   \         //
root->left =new Node(20)  ;                //     20    70        //            
root->right =new Node(70) ;                //    /   \            //       
root->left->left = new Node(10) ;          //   10   40           //        
root->left->right = new Node(40) ;         //      /  \           //    
root->left->right->left = new Node(30) ;   //     30   50         //    
root->left->right->right =new Node(50)  ;  ///////////////////////// 


    
    cout << "Preorder Traversal: \n" ;
    Preorder(root);
    
    cout << "\nInorder Traversal: \n" ;
    Inorder(root);
    
    cout << "\nPostorder Traversal: \n" ;
    Postorder(root);
    
    cout << "\n";
    
    return 0;
}

