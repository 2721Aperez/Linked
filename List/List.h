#pragma once
#include "Node.h";
#include <stack>;

using namespace std;

class List
{
private:
	Node* head;
public:
	List()
	{
		head = nullptr;
	}
	~List() {}
	int findKLast(int k);
	void remove(int data);
	void printList();
	void push(Node** head_ref, int new_data);
	void insert(int data);
	int getLength();
	bool isEmpty();
	void reverseList();
	bool isPalindron();
	int size();
	Node* sumLists(Node* A, Node* B);
	void SwapNodes();
	void Rotate(int k);
};