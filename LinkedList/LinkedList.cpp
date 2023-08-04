#include<iostream>

template <typename T>
class LinkedList
{
private:
	class Node
	{
	public:
		Node* next;
		T value;

		Node(T value, Node* next = nullptr) : value{value}, next{next}{}
	};
	Node* head;
	Node* tail;
	int size;

	void printList(Node* current) const
	{
		if (current == nullptr)
		{
			return;
		}
		std::cout << current->value << " ";
		printList(current->next);
		
	}
public:
	LinkedList() : size{ 0 }, head{ 0 }, tail{ 0 }{}

	LinkedList(std::initializer_list<T> values)
	{
		
	}
	LinkedList(const LinkedList& obj)
	{

	}
	~LinkedList()
	{

	}
	void addFront (T value)
    {
		Node* newNode = new Node(value, head);
		head = newNode;
		if(!tail)
		{
			tail = head;
		}
		size++;
	}
	void addBack(T value)
	{
		Node* newNode = new Node(value);
		if(!tail) 
		{
			tail = newNode;
			head = tail;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}
	void removeFront()
	{
		if(head != nullptr)
		{
			Node* current = head;
			head = head->next;
			if (head == nullptr)
			{
				tail = nullptr;
			}
			delete current;
			size--;
		}
	}
	void removeBack()
	{
		if (head == nullptr)
		{
			return;
		}
		if (head ->next == nullptr)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			size--;
			return;
		}
		Node* current = head;
		while (current->next->next !=nullptr)
		{
			current = current->next;
		}
		delete current->next;
		current->next = nullptr;
		tail = current;
		size--;
	}
	bool isEmpty() const
	{
		return size <= 0;
	}
	int getSize() const
	{
		return size;
	}
	bool search(T value)
	{
		Node* current = head;
		while (current!=nullptr)
		{
			if (value == current->value)
			{
				return true;
			}
			current = current->next;
			
		}
		return false;
	}
	void printList() const
	{
		printList(head);
	}
	void insert(int index, T value)
	{
		if(index < 0 || index > size)
		{
			return;
		}
		if(index == 0)
		{
			addFront(value);
			return;
		}
		if(index == size)
		{
			addBack(value);
			return;
		}
		Node* current = head;
		int counter = 0;
		while (current!=nullptr )
		{
			if (counter == index - 1)
			{
				Node* newNode = new Node(value, current->next);
				current->next = newNode;
				size++;
				return;
			}
			counter++;
			current = current->next;
		}
	}

	void remove(int index)
	{
		if (index < 0 || index > size - 1)
		{
			return;
		}
		if (index == 0)
		{
			removeFront();
			return;
		}
		if (index == size - 1)
		{
			removeBack();
			return;
		}
		Node* current = head;
		int counter = 0;
		while (current != nullptr)
		{
			if (counter == index - 1)
			{
				Node* tmp = current->next;
				current->next = tmp->next;
				delete tmp;
				size--;
				return;
			}
			counter++;
			current = current->next;
		}
	}
};


int main()
{
	LinkedList<int>list;
	list.addFront(1);
	list.addFront(3);
	list.addFront(5);
	
	list.printList();
	std::cout << std::endl;

	list.addBack(9);
	list.addBack(6);
	list.addBack(11);

	list.printList();
	std::cout << std::endl;

	std::cout << list.getSize() << std::endl;

	list.removeBack();
	list.printList();
	std::cout << std::endl;

	list.removeFront();
	list.printList();
	std::cout << std::endl;

	list.insert(2, 15);
	list.printList();
	std::cout << std::endl;

	list.remove(2);
	list.printList();
	std::cout << std::endl;

}
		
