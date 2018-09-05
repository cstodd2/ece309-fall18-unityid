#include <stdio.h>

class Item {
public:
  const char * str;
  Item(const char *as = "") 
  { 
    str = as; 
  }
};


class List {
private:

// ListNode represents each 
// node of the list
  class ListNode {
  private:
    Item item; // data in the list
    ListNode *next;	
  public:
    ListNode(Item a) 
    { 
      item = a; 
      next=NULL; // automatically serves as a list tail
    }
    ListNode* getNext() 
    { 
      return next; 
    }
    void setNext(ListNode *n) 
    { 
      next = n; 
    }
    Item getItem() 
    { 
      return item; 
    }
  };

  // add head and tail pointer
  ListNode *head;
  ListNode *tail;


  
public:
  List();
  ~List();
  Item get(int n);
  int length();
  void push_back(const char* a);    
  Item remove_front();    
  bool empty(); 
};

Item List::get(int n)
{
	ListNode* y = head;

	for(int i = 1; i < n; i++)
	{
		y = y -> getNext();
	}
	return y -> getItem();
}

int List::length()
{
	ListNode* n = head -> getNext();
	if(empty())
	{
		return 0;
	}
	int count = 0;
	if(n == NULL)
	{
		return 1;
	}
	else
	{
		count++;
		for(count = 1; n!=NULL; count++)
		{
			n = n ->getNext();
		}
		return count;		
	}
}

List::List()
{
  // start with an empty list
  head = NULL;
  tail = NULL;
}

List::~List()
{
	
	while(!empty())
    {
	  Item temp;
      temp = remove_front();

      printf("Items being deleted: %s\n",temp.str);
    }
}

void List::push_back(const char* a)
{
  Item b(a);
  ListNode *node = new ListNode(a);
  if (head == NULL)
    {
      // list is empty
      head = node;
      tail = node;
    }
  else 
    {
      tail->setNext(node);
      tail = node;
    }
}

Item List::remove_front() 
{
  Item copy;
  if (!empty()) // if list is not empty
    {
      copy = head->getItem(); // return copy
      ListNode *tmp = head->getNext();
      delete head; // delete the node
      head = tmp;  // update the head
      if (tmp==NULL) // removed last element 
	  tail = NULL;
      return copy;
    }
  else
  {
	return Item (" "); 
  }
  //return false; // nothing in list
}

bool List::empty()
{
  return head==NULL;
}


