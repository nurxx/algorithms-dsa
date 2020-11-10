#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node*next;

	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};
struct List {
	Node*head;
	Node*tail;

	List()
	{
		this->tail = nullptr;
		this->head = nullptr;
	}
};

void insertAtTail(List *list, int data)
{
	Node*last = new Node(data);
	if (list->head == nullptr)
	{
		list->head = last;
		list->tail = last;
	}
	else {
		list->tail->next = last;
		list->tail = last;
		list->tail->next = nullptr;
	}
}
void printList(List*list)
{
	Node*current = list->head;
	cout << "Elements in Linked List: \n";
	while (current)
	{
		cout << current->data << endl;
		current = current->next;
	}
}

void insertAtHead(List *list, int data)
{
	Node*first = new Node(data);
	if (list->head == nullptr)
	{
		list->head = first;
		list->tail = first;
	}
	else {
		first->next = list->head;
		list->head = first;
	}
}
bool searchInLinkedList(List*list, int data)
{
	Node*current = list->head;
	while (current)
	{
		if (current->data == data)return true;
		current = current->next;
	}
	return false;
}
int searchPosOfElement(List *list, int data)
{
	Node*current = list->head;
	int pos = 0;
	while (current)
	{
		pos++;

		if (current->data == data)return pos;
		current = current->next;
	}
	return -1;
}
void printInReverse(Node*head)
{
	Node*current = head;
	cout << "Printing in reverse:  \n";
	if (head != nullptr)
	{
		printInReverse(current->next);
		cout << current->data << endl;
	}
}
void ReverseLinkedList(List *list)
{
	Node *prev = nullptr;
	Node*current = list->head;
	Node*next = nullptr;

	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	list->head = prev;
}
void ReverseFirstKNodes(List*list, int k)
{
	int count = 1;
	Node*temp = list->head;

	while (count < k)
	{
		temp = temp->next;
		count++;
	}

	Node*kth = temp->next;
	cout << kth->data << endl;
	temp->next = nullptr;

	Node*prev = nullptr;
	Node *next = nullptr;
	Node*current = list->head;

	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	list->head = prev;
	current = list->head;
	while (current->next!=nullptr)
	{
		current = current->next;
	}
	current->next = kth;
}
void deleteFromList(List*list, int pos)
{
	if (list->head == nullptr)return;
	int count = 1;
	Node*temp = list->head;
	while (count < pos-1)
	{
		temp = temp->next;
		count++;
	}
	temp->next = temp->next->next;
}
void insertAtSpecificPos(List*list, int pos,int data)
{
	if (list->head == nullptr)return;

	Node*temp = list->head;
	int count = 1;
	while (count < pos - 1)
	{
		temp = temp->next;
		count++;
	}
	Node* added = new Node(data);
	added->next = temp->next;
	temp->next = added;
}
int size(List*list)
{
	Node*current = list->head;
	int size = 0;
	while (current)
	{
		size++;
		current = current->next;
	}
	return size;
}
int main()
{
	List *list = new List();
	//insertAtHead(list, 1);
	//insertAtHead(list, 2);
	//insertAtHead(list, 3);
	insertAtTail(list, 1);
	insertAtTail(list, 2);
	insertAtTail(list, 5);
	insertAtTail(list, 3);
	insertAtTail(list, 4);
	//cout << list->tail->data << endl;
	//cout << "SIZE : " << size(list) << endl;
	//printList(list);
	//cout << searchInLinkedList(list,1) << endl;
	//cout << searchInLinkedList(list, 8) << endl;

	//cout << searchPosOfElement(list, 2) << endl;
	//cout << searchPosOfElement(list, 18) << endl;
	//printInReverse(list->head);
	//ReverseLinkedList(list);
	//ReverseFirstKNodes(list, 3);
	//deleteFromList(list, 3);
	insertAtSpecificPos(list, 6, 8);
	printList(list);

	//cout << "SIZE : " << size(list) << endl;

	system("pause");
	return 0;
}