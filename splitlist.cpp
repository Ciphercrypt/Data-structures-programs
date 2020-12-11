#include <iostream>
using namespace std;

struct node
{
  int num;
  struct node *next;
} *head;

void create_list (int n)
{
  int i, num;
  struct node *ptr, *newnode;

  if (n >= 1)
    {
      head = (struct node *) malloc (sizeof (struct node));

      cout << "Enter data of the list:\n";
      cin >> num;
      head->num = num;
      head->next = NULL;
      ptr = head;
      for (i = 2; i <= n; i++)
	{
	  newnode = (struct node *) malloc (sizeof (struct node));
	  cin >> num;
	  newnode->num = num;
	  newnode->next = NULL;
	  ptr->next = newnode;
	  ptr = newnode;
	}
      ptr->next = head;
    }
}

void display (struct node *head)
{
  struct node *tmp;
  int n = 1;

  if (head == NULL)
    {
      cout << "List is empty";
    }
  else
    {
      tmp = head;


      do
	{
	  cout << tmp->num << " ";
	  tmp = tmp->next;
	  n++;
	}
      while (tmp != head);
    }
}

void Frontbacksplit (struct node **L1head, struct node **L2head)	
{
  struct node *slow = head;
  struct node *fast = head;

  if (head == NULL)
    return;

  while (fast->next != head && fast->next->next != head)
    {
      fast = fast->next->next;
      slow = slow->next;
    }

  if (fast->next->next == head)
    fast = fast->next;

  *L1head = head;

  if (head->next != head)
    *L2head = slow->next;


  fast->next = slow->next;


  slow->next = head;
}

int main ()
{
  int n;
  struct node *L1head = NULL;
  struct node *L2head = NULL;
  head = NULL;
  cout << "Enter the size of  linked list: ";
  cin >> n;
  create_list (n);
  cout<<"Original linked list\n";
  display (head);
  Frontbacksplit (&L1head, &L2head);
  cout << "\nFirst linked list data: ";
  display (L1head);
  cout << "\nSecond linked list data: ";
  display (L2head);
  return 0;
}


