#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
	int data;
	Node*next;

	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};

struct LinkedList {
	Node*head;
	Node*tail;
	LinkedList()
	{
		this->head = nullptr;
		this->tail = nullptr;
	}
};
void insertAtHead(LinkedList *list, int val)
{
	Node*node = new Node(val);
	if (list->head == nullptr)
	{
		list->head = node;
		list->tail = node;
	}
	else {
		node->next = list->head;
		list->head = node;
	}
}
void insertAtTail(LinkedList *list, int val)
{
	Node*node = new Node(val);
	if (list->head == nullptr)
	{
		list->head = node;
		list->tail = node;
	}
	else {
		list->tail->next = node;
		list->tail = node;
	}
	cout << "add_last";
}

int getSize(LinkedList *list)
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

void add(LinkedList *list, int val, int pos) {

	Node*node = new Node(val);

	if (pos<0 || pos>getSize(list))
	{
		insertAtTail(list, val);
	}
	else if (pos == 0)
	{
		insertAtHead(list, val);
	}
	else {
		int count = 1;
		Node*current = list->head;
		while (count<pos)
		{
			count++;
			current = current->next;

		}
		node->next = current->next;
		current->next = node;
	}
}

void print(LinkedList *list) {
	Node*current = list->head;
	while (current)
	{
		cout << current->data << '#';
		current = current->next;
	}
}

void remove(LinkedList *list, int pos) {
	Node*temp = list->head;
	Node*prev = nullptr;
	if (pos<0 || list->head == nullptr)
	{
		cout << "remove_failed";
		return;
	}
	else if (pos == 0)
	{
		list->head = list->head->next;
	}
	else {
		while (pos>0 && temp->next != nullptr)
		{
			prev = temp;
			temp = temp->next;
			pos--;
		}
		if (pos>0)
		{
			cout << "remove_failed";
			return;
		}
		else if (temp->next == nullptr)
		{
			prev->next = nullptr;
			list->tail = prev;
		}
		else {
			prev->next = temp->next;
		}
	}
}

void reverse(LinkedList *list) {
	Node *next = nullptr;
	Node *current = list->head;
	Node *prev = nullptr;

	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	list->head = prev;
}

void remove_all(LinkedList *list, int val) {
	Node*current = list->head;
	Node*prev;
	while (current != nullptr &&current->data == val)
	{
		list->head = current->next;
		current = list->head;
	}


	while (current != nullptr)
	{
		while (current != nullptr && current->data != val)
		{
			prev = current;
			current = current->next;
		}

		if (current == nullptr) return;

		prev->next = current->next;

		current = prev->next;
	}
}

void group(LinkedList *list, int a, int b) {

	if (a<0 || b<0 || a>getSize(list) - 1 || b>getSize(list) - 1 || a>b)
	{
		cout << "fail_grouping";
		return;
	}

	else if (a == b)return;

	else {
		Node *start = list->head;
		int startPos = a;
		int diff = (b - a);

		while (a != 0)
		{
			start = start->next;
			a--;
		}
		Node*sum = start->next;

		while (diff>0 && b>0 && sum)
		{
			start->data += sum->data;
			sum = sum->next;
			remove(list, startPos + 1);

			diff = diff - 1;
		}

	}
}

void count(LinkedList*list, int val) {
	int count = 0;
	Node*current = list->head;
	while (current)
	{
		if (current->data == val)count++;

		current = current->next;
	}
	cout << count;
}

void is_palindrome(LinkedList*list) {
	Node*current = list->head;
	string s = "";
	while (current)
	{
		s += to_string(current->data);
		current = current->next;
	}
	int start = 0;
	int end = s.length() - 1;
	while (start<end)
	{
		if (s[start++] != s[end--])
		{
			cout << "false";
			return;
		}
	}
	cout << "true";

}


int main() {
	int cases;
	std::cin >> cases;
	for (int i = 0; i < cases; i++) {
		LinkedList *ll = new LinkedList();
		int ops;
		std::string op;
		std::cin >> ops;
		for (int j = 0; j < ops; j++) {
			std::cin >> op;

			if (op == "count") {
				int arg1;
				std::cin >> arg1;
				count(ll, arg1);
			}

			if (op == "add") {
				int arg1, arg2;
				std::cin >> arg1 >> arg2;
				add(ll, arg1, arg2);
			}

			if (op == "print") {
				print(ll);
			}

			if (op == "remove") {
				int arg1;
				std::cin >> arg1;
				remove(ll, arg1);
			}

			if (op == "reverse") {
				reverse(ll);
			}

			if (op == "remove_all") {
				int arg1;
				std::cin >> arg1;
				remove_all(ll, arg1);
			}

			if (op == "group") {
				int arg1, arg2;
				std::cin >> arg1 >> arg2;
				group(ll, arg1, arg2);
			}

			if (op == "is_palindrom") {
				is_palindrome(ll);
			}
		}

		std::cout << std::endl;

	}
	return 0;
}