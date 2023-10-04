// Include header file
#include <iostream>
using namespace std;
// C++ program for
// Swap first and last nodes in circular Linked List

// Define class of linked list Node
class LinkNode
{
	public: int data;
	LinkNode *next;
	LinkNode(int data, LinkNode *first)
	{
		this->data = data;
		this->next = first;
	}
};
class CircularLinkedList
{
	public: LinkNode *head;
	// Class constructor
	CircularLinkedList()
	{
		this->head = nullptr;
	}
	// Insert node at end of circular linked list
	void insert(int value)
	{
		// Create a new node
		LinkNode *node = new LinkNode(value, this->head);
		if (this->head == nullptr)
		{
			// First node of linked list
			this->head = node;
			node->next = this->head;
		}
		else
		{
			LinkNode *temp = this->head;
			// Find the last node
			while (temp->next != this->head)
			{
				// Visit to next node
				temp = temp->next;
			}
			// Add new node at the last 
			temp->next = node;
		}
	}
	// Display node element of circular linked list
	void display()
	{
		if (this->head == nullptr)
		{
			cout << "Empty Linked List" << endl;
		}
		else
		{
			cout << "Linked List Element :";
			LinkNode *temp = this->head;
			// iterate linked list
			while (temp != nullptr)
			{
				// Display node
				cout << " " << temp->data;
				// Visit to next node
				temp = temp->next;
				if (temp == this->head)
				{
					// Stop iteration
					return;
				}
			}
		}
	}
	// Swap or exchange first and last nodes
	void swapNode()
	{
		if (this->head == nullptr)
		{
			cout << "Empty linked list";
			return;
		}
		else if (this->head->next == this->head)
		{
			// Only onle element of linked list
			cout << "\n Only One element of linked list";
			return;
		}
		// Auxiliary variables
		LinkNode *temp = this->head;
		LinkNode *first = this->head;
		LinkNode *prev = this->head;
		while (temp->next != this->head)
		{
			// Get second last node
			prev = temp;
			// Find last node
			temp = temp->next;
		}
		if (prev == this->head)
		{
			// Only two element in this linked list
			// So set second node as head
			this->head = prev->next;
		}
		else
		{
			// Swap node link
			// That is last node
			temp = prev->next;
			// Modified link 
			temp->next = first->next;
			prev->next = this->head;
			first->next = temp;
			// Make last node to head
			this->head = temp;
		}
	}
};
int main()
{
	CircularLinkedList *cll = new CircularLinkedList();
	// Insert element of linked list
	cll->insert(1);
	cll->insert(3);
	cll->insert(5);
	cll->insert(2);
	cll->insert(6);
	cll->insert(7);
	cout << "\n Before ";
	// Before swap
	// Display all nodes
	cll->display();
	cll->swapNode();
	cout << "\n After  ";
	// After swap
	// Display all nodes
	cll->display();
	return 0;
}
