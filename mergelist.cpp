#include <iostream>

using namespace std;

struct Node
{
  int data;
  struct Node *next;
};

void insertAfter(struct Node* prev_node, struct Node* to_insert)
{
    if (prev_node == NULL)
    {
       cout <<"the given previous node cannot be NULL";
       return;
    }

    to_insert->next = prev_node->next;
    prev_node->next = to_insert;

}

void mergeLists(struct Node* Llist1, struct Node* Llist2) {
    while(Llist1->next != NULL) {
        Node* next_Llist2 = Llist2->next;
        insertAfter(Llist1, Llist2);

        if (next_Llist2 == NULL) break;

        Llist2 = next_Llist2;
        Llist1 = Llist1->next->next;
    }

    Llist1->next = Llist2;
}

void append(struct Node** head, struct Node* to_insert)
{

    to_insert->next = NULL;
    if (*head == NULL)
    {
       *head = to_insert;
       return;
    }

    struct Node *last = *head;
    while (last->next != NULL)
        last = last->next;

    last->next = to_insert;
    return;
}

void sortedInsert(struct Node** head, struct Node* new_node) 
{ 
    struct Node* current; 
    if (*head == NULL || (*head)->data >= new_node->data) 
    { 
        new_node->next = *head; 
        *head = new_node; 
    } 
    else
    { 
        current = *head; 
        while (current->next!=NULL && 
               current->next->data < new_node->data) 
        { 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
} 

void Sort_Llist(struct Node **head) 
{ 
    struct Node *sorted = NULL; 
  
    struct Node *current = *head; 
    while (current != NULL) 
    { 
        struct Node *next = current->next; 
  
        sortedInsert(&sorted, current); 
  
        current = next; 
    } 
  
    *head = sorted; 
} 



void printList(struct Node *node)
{
  while (node != NULL)
  {
     cout << node->data << " ";
     node = node->next;
  }
}

int main(){

    int n, k, a, b;
    struct Node* Llist1 = NULL;
    struct Node* Llist2 = NULL;

    cout << "Enter number of elements in  list 1: " << endl;
    cin >> n;

    for ( int i = 0 ; i < n ; i++ ){
        cout << "Enter elements of list 1: " << endl;
        cin >> a;
        Node* node_to_append = new Node();
        node_to_append->data = a ;
        append(&Llist1, node_to_append);
    }

    cout << "Enter number of elements in  list 2: " << endl;
    cin >> k;

    for ( int i = 0 ; i < k ; i++ ){
        cout << "Enter elements of list 2: " << endl;
        cin >> b;
        Node* node_to_append = new Node();
        node_to_append->data = b ;
        append(&Llist2, node_to_append);

    }

    mergeLists(Llist1, Llist2);

    cout <<"Created Linked list is: \n";
    printList(Llist1);
    Sort_Llist(&Llist1);
    cout<<"\nSorted List:";
    printList(Llist1);
    
   

  return 0;
}

