#include<iostream>
using namespace std;

struct Node
{

    int data;
    Node* left;
    Node* right;

 
};


Node* getNewNode(int data)
{

    Node* node = new Node();
    node->data=data;
    node->left = node->right =NULL;
    return node;

}

Node* insertNode(Node* root, int data)
{

    if(root==NULL)
        root=getNewNode(data);
    else if (data <= root->data)
        root->left=insertNode(root->left,data);
    else
        root->right=insertNode(root->right,data);

    return root;

}

bool search(Node* root, int data)
{

    if(root==NULL)
        return false;
    else if(root->data==data)
        return true;
    else if(data <= root->data)
        return search(root->left, data);
    else
        return search(root->right, data);

}






void inOrder(Node* root)
{
    if(root==NULL)
        return ;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}


int minElement(Node* root)
{


    if(root == NULL)
        return 0;
    while(root->left!=NULL)
        root=root->left;
    return root->data;
}







Node* deleteNode(Node* root, int data)
{
    if(root==NULL)
        return root;
    else if(data < root->data) root->left = deleteNode(root->left, data);
    else if (data > root->data) root->right = deleteNode(root->right, data);
    else {

        if(root->left==NULL && root->right == NULL){
            delete(root);
            root=NULL;

        }
        else if(root->left==NULL)
        {
            Node* temp=root;
            root=root->right;
            delete temp;
        }else if(root->right==NULL)
        {
            Node* temp=root;
            root=root->left;
            delete temp;
        }
        else{

            int minValue = minElement(root->right);
            root->data=minValue;
            root->right=deleteNode(root->right, minValue);

        }
    }

    return root;
}

Node* findNode(Node* root, int data)
{
    if(root==NULL)
        return root;

    else if(root->data == data)
            return root;

    else if(data < root->data) return findNode(root->left, data);

    else return findNode(root->right, data);
}




int main()
{

    Node* root=NULL, *temp;
    int i,k;

    cout<<"Choose the operation to perform on BST\n1.Insertion\n2.Deletion\n3.searching\n4.printing BST\n5.Exit\n";
    cin>>i;
     if(i==1){
           
        cout<<"Enter element to be inserted in BST\n";
        cin>>k;
        root=insertNode(root,k);
        main();
        }
        
        if(i==2)
        {
            
            cout<<"Enter value to be deleted!\n";
            cin>>k;
            deleteNode(root, k);
            main();
        }
        if(i==3)
        {
            
            cout<<"Enter element to be searched in BST\n";
            cin>>k;
            if(search(root,k)){
                cout<<k<<" is present in BST\n";
            }
            else{
                cout<<k<<"is NOT prsent in BST\n";
            }
            main();
        }   
        if(i==4)
        {
           cout<<"Inorder traversal of BST :\n";
           inOrder(root);
           main();
        
        }
        if(i==5)
        {
            cout<<"Thank you!"<<endl;
        }

    


    return 0;
}