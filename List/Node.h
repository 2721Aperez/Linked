#pragma once

class Node
{
public:
	Node* next;
	int val;
	Node(int x) { this->val = x; this->next = nullptr; }
};