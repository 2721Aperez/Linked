#include<iostream>;
#include "List.h"

using namespace std;

void List::insert(int data)
{
	if (!head)
	{
		Node* node = new Node(data);
		head = node;
	}
	else
	{
		Node* temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		Node* node = new Node(data);
		temp->next = node;
	}
}
bool List::isEmpty()
{
	return (!head) ? true : false;
}
void List::printList()
{
	if (isEmpty())
	{
		std::cout << "Empty List" << std::endl;
		return;
	}
	Node* current = head;
	while (current)
	{
		std::cout << current->val << "->";
		current = current->next;
	}
	std::cout << "NULL" << std::endl;
}

int List::getLength()
{
	if (!head) { return 0; }
	Node* current = head;
	int count = 1;
	while (current->next)
	{
		count++;
		current = current->next;
	}
	return count;
}

void List::remove(int pos)
{

	if (pos > getLength()) { std::cout << "No index exists"; return; }

	if (pos == 0)
	{
		Node* current = head;
		current = head->next;
		delete head;
		head = current;
	}
	else
	{
		Node* current = head;
		Node* first = current->next;
		Node* prev = nullptr;
		for (int i = 0; i < pos; i++)
		{
			prev = current;
			current = current->next;
			first = first->next;
		}
		prev->next = first;
		delete[]current;

	}

}

int recursiveK(Node* head, int k)
{
	if (!head)
	{
		return 0;
	}
	int i = recursiveK(head->next, k) + 1;

	if (i == k) { return head->val; }
}
int List::findKLast(int k)
{
	Node* current = head;

	return recursiveK(current, k);
}

void List::reverseList()
{
	if (!head) { return; }
	else
	{
		Node* current = head;
		Node* prev = nullptr;
		while (current)
		{
			Node* nex = current->next;
			current->next = prev;
			prev = current;
			current = current->next;
		}
	}
}
int List::size()
{
	Node* temp = head;
	int count = 0;
	while (temp) { temp = temp->next; count++; }

	return count;
}
void List::push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node(new_data);

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}
bool List::isPalindron()
{
	if (!head) { return false; }
	stack<Node*>nodes;
	Node* current = head;
	Node* fast = head;
	nodes.push(current);
	while (fast->next != nullptr)
	{
		fast = fast->next->next;
		current = current->next;
		nodes.push(current);
	}

	while (current)
	{
		cout << nodes.top()->val << " " << current->val << endl;
		if (nodes.top()->val != current->val) { return false; }
		nodes.pop();
		current = current->next;
	}

	return true;
}

/*Node* List::sumLists(Node* A, Node* B)
{
	Node* new_list = nullptr;
	Node* temp, * prev = nullptr;
	int carry = 0, sum;

	while (A != NULL || B != NULL)
	{

		sum = carry + (A ? A->val : 0) +
			(B ? B->val : 0);


		carry = (sum >= 10) ? 1 : 0;


		sum = sum % 10;


		temp = new Node(sum);


		if (new_list == NULL){new_list = temp;}

		else{prev->next = temp;}

		prev = temp;

		// Move first and second pointers to next nodes
		if (A) { A = A->next; }
		if (B) { B = B->next; }
	}

	if (carry > 0) { temp->next = new Node(carry); }

	return new_list;
}
*/
/*Given the head of a singly linked list, swap every two nodes and return its head.

For example, given 1 -> 2 -> 3 -> 4, return 2 -> 1 -> 4 -> 3.*/

void List::SwapNodes()
{
	if (!head) { cout << "EMpty List " << endl; return; }
	if (size() < 2) { cout << "List is too small" << endl; return; }

	Node* temp = head;
	Node* faster = temp->next;
	int count = 0;
	int temp_value = 0;

	temp_value = temp->val;
	temp->val = faster->val;
	faster->val = temp_value;

	while (faster->next != nullptr)
	{
		faster = faster->next;
		temp = temp->next;
		count++;

		if (count % 2 == 0)
		{
			temp_value = temp->val;
			temp->val = faster->val;
			faster->val = temp_value;
		}
	}
}

void List::Rotate(int k)
{
	Node* temp_tail = head;
	int count = 0;

	if (k == 0) { return; }

	while (temp_tail->next) { temp_tail = temp_tail->next; }

	while (count++ < k)
	{
		Node* temp_head = head->next;

		temp_tail->next = head;
		temp_tail = head;
		head = temp_head;

		temp_tail->next = nullptr;
	}
}