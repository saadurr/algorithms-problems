#include <iostream>
#include <stack>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node() = default;
	Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
	Node* head;
public:
	LinkedList()
	{
		head = nullptr;
	}
	void Add(int value)
	{
		if (IsEmpty())
		{
			head = new Node(value);
			return;
		}

		Node* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}

		temp->next = new Node(value);

	}

	void PrintList()
	{
		if (IsEmpty())
		{
			cout << "\n\t---- List is empty -----\n";
			return;
		}
		cout << "\n";
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->data << " -> ";
			current = current->next;
		}

	}

	bool Remove(int value)
	{
		if (IsEmpty())
		{
			cout << "\n\tERROR: List is empty.\n";
			return false;
		}

		if (head->data == value)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			return true;
		}

		Node* current = head, *previous = head;
		while (current != nullptr)
		{
			if (current->data == value)
			{
				previous->next = current->next;

				//current = nullptr;
				delete current;
				return true;
			}
			previous = current;
			current = current->next;
		}
		cout << "\nItem to be removed does not exist in list.\n";
		return false;
	}

	bool ValueExists(int value)
	{
		if (IsEmpty())
			return false;

		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->data == value)
				return true;
			temp = temp->next;
		}

		return false;
	}

	bool IsEmpty()
	{
		if (head == nullptr)
			return true;

		return false;
	}

	Node* GetHead()
	{
		return head;
	}

	~LinkedList()
	{
		if (IsEmpty())
			return;

		cout << "\n\n---- Destroying Linked List ----\n";
		
		Node* current = head, *temp;
		
		while (current != nullptr)
		{
			temp = current;
			current = current->next;
			delete temp;
		}
	}
};

LinkedList* ReverseList(LinkedList& list)
{
	LinkedList* reversed = new LinkedList();
	if (list.IsEmpty())
	{
		cout << "Empty List\n";
		return &list;
	}
	Node* current = list.GetHead();
	stack <int> s;
	while (current != nullptr)
	{
		s.push(current->data);
		current = current->next;
	}

	int temp;
	while (!s.empty())
	{
		temp = s.top();
		s.pop();

		reversed->Add(temp);
	}

	return reversed;
}

int main()
{
	LinkedList l1;
#if 0
	l1.Add(1);
	l1.Add(2);
	l1.Add(3);
	l1.PrintList();
	l1.Remove(2);
	l1.Remove(1);
	l1.Remove(4);
	l1.Remove(3);
	l1.PrintList();
	l1.Remove(3);
#endif
	l1.Add(1);
	l1.Add(2);
	l1.Add(3);
	l1.PrintList();
	LinkedList *l2 = ReverseList(l1);
	l2->PrintList();
	return 0;
}