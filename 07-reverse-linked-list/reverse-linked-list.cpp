#include <iostream>
#include <stack>

using namespace std;

template <typename T>
struct Node
{
	T data;
	Node* next;
	Node() = default;
	Node(T value) : data(value), next(nullptr) {}
};


template<typename T>
class LinkedList
{
private:
	Node<T>* head;
public:
	LinkedList()
	{
		head = nullptr;
	}
	void Add(T value)
	{
		if (IsEmpty())
		{
			head = new Node<T>(value);
			return;
		}

		Node<T>* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}

		temp->next = new Node<T>(value);

	}

	void PrintList()
	{
		if (IsEmpty())
		{
			cout << "\n\t---- List is empty -----\n";
			return;
		}
		cout << "\n";
		Node<T>* current = head;
		while (current != nullptr)
		{
			cout << current->data << " -> ";
			current = current->next;
		}

	}

	bool Remove(T value)
	{
		if (IsEmpty())
		{
			cout << "\n\tERROR: List is empty.\n";
			return false;
		}

		if (head->data == value)
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
			return true;
		}

		Node<T>* current = head, *previous = head;
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

	bool ValueExists(T value)
	{
		if (IsEmpty())
			return false;

		Node<T>* temp = head;
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

	Node<T>* GetHead()
	{
		return head;
	}

	~LinkedList()
	{
		if (IsEmpty())
			return;

		cout << "\n\n---- Destroying Linked List ----\n";
		
		Node<T>* current = head, *temp;
		
		while (current != nullptr)
		{
			temp = current;
			current = current->next;
			delete temp;
		}
	}
};

template <typename T>
LinkedList<T>* ReverseList(LinkedList<T>& list)
{
	LinkedList<T>* reversed = new LinkedList<T>();
	if (list.IsEmpty())
	{
		cout << "Empty List\n";
		return &list;
	}
	Node<T>* current = list.GetHead();

	stack <T> s;
	while (current != nullptr)
	{
		s.push(current->data);
		current = current->next;
	}

	T temp;
	while (!s.empty())
	{
		temp = s.top();
		s.pop();

		reversed->Add(temp);
	}

	return reversed;
}

template <typename T>
void ReverseList2(LinkedList<T>& list)
{

}

int main()
{
	LinkedList<int> l1;
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
	LinkedList<int> *l2 = ReverseList(l1);
	l2->PrintList();
	return 0;
}