#include <iostream>
using namespace std;

// Linked list node using an integer as the data payload
class Node
{
public:
	int data;
	Node* next;
};

// Linked list with basic add and print functionality
class LinkedList
{
private:
	Node *head;

public:
	LinkedList()
	{
		head = nullptr;
	}

	void addNode(int data)
	{
		Node *newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;

		if (!head) // If head is null the list is empty, just set head to newNode and we are done
		{
			head = newNode;
		}
		else
		{
			if (!head->next) // If head exists but head->next does not, there is only one node. Set head->next to newNode and we are done
			{
				head->next = newNode;
			}
			else // Last scenario, there are multiple nodes...loop through to find end of list and set the last node's next to newNode
			{
				Node *tempNode = head->next;
				while (tempNode->next)
				{
					tempNode = tempNode->next;
				}
				tempNode->next = newNode;
			}
		}
	}

	void printList()
	{
		while (head)
		{
			cout << head->data << " ";
			head = head->next;
		}
		cout << endl;
	}
};



int main()
{
	LinkedList list;
	list.addNode(1);
	list.addNode(25);
	list.addNode(17);

	list.printList();
}