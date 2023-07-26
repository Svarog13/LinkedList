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
//
//Реалізувати клас LinkedList, який представляє однозв'язний список цілих чисел. Клас має мати наступні методи:
//1.	addFront(int value) : Додає новий вузол з заданим значенням на початок списку.
//2.	addBack(int value) : Додає новий вузол з заданим значенням в кінець списку.
//3.	removeFront() : Видаляє перший вузол зі списку.
//4.	removeBack() : Видаляє останній вузол зі списку.
//5.	isEmpty() : Перевіряє, чи є список порожнім.
//6.	getSize() : Повертає кількість елементів у списку.
//7.	search(int value) : Повертає true, якщо задане значення знаходиться у списку, і false - в іншому випадку.
//8.	printList() : Виводить всі елементи списку на екран.

//Додати наступне до класу «Просто підключений список»
//функції : вставка елемента в задану позицію - insert(index, value) , 
// видалення елемент в даній позиції - remove(index)
// пошук даного елемента (функція повертає позицію знайденого елемента в якщо успішний або NULL якщо невдалий). - find(value

//	1. Реалізувати шаблонний клас «Черга» на основі
//	двосторонній список.
//	2. Створити шаблон Клас контейнера Array, який
//	це масив, який дозволяє зберігати
//	об'єктів зазначеного типу. Клас повинен реалізувати
//	Наступні функції :
//A) GetSize - отримання розміру масиву(кількість
//елементи, для яких виділена пам'ять);
//B) SetSize(int size, int grow = 1) - встановити розмір масиву
//(якщо параметр розміру більший за попередній розмір
//	масив, потім виділяється додатковий блок пам'яті,
//	якщо ні, то втрачаються «зайві» елементи і пам'ять
//	звільняється); параметр зростання визначає, скільки елементів вибрати
//	пам'ять, якщо кількість елементів перевищує
//	поточний розмір масиву.Наприклад, SetSize(5, 5);
//означає, що при додаванні 6 - го елемента,
//масив стає 10 при додаванні
//11 - 15 т.д.;
//C) GetUpperBound - отримання останнього дійсного
//індекс в масиві.Наприклад, якщо
//масив 10, ви додаєте до нього 4 елементи, потім
//функція поверне 3;
//D) IsEmpty - чи є масив порожнім ?
//E) FreeExtra - видалити «надлишкову» пам'ять (вище останнього допустимого індексу);
//F) RemoveAll - видалити всі;
//G) GetAt - отримання певного елемента(на
//індекс);
//H) SetAt - встановлення нового значення для певного елемента(індекс елемента повинен бути
//менше поточного розміру масиву);
//I) оператор[] - для реалізації двох попередніх
//функції;
//J) Додати - додавання елемента в масив(при необхідності масив збільшується на величину зростання
//функції SetSize);
//K) Append - «додавання» двох масивів;
//l) оператор = ;
//M) GetData - отримання адреси масиву з даними;
//N) InsertAt - вставка елементів у задану позицію O.RemoveAt - видалення елементів з
//призначена посада.
