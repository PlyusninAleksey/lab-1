#pragma once
#include <iostream>
template<typename T>
class Node
{public:
	T data;
	Node<T>* nextPtr;

	Node():nextPtr(nullptr) {}
	Node(T value, Node* next = nullptr) : data(value), nextPtr(next) {}
	Node(const Node& obj) : data(obj.data), nextPtr(obj.nextPtr) {}

	bool operator==(const Node& obj) const noexcept
	{
		return ((data == obj.data) && (nextPtr == obj.nextPtr));
	}

	bool operator!=(const Node& obj) const noexcept
	{
		return ((data != obj.data) || (nextPtr != obj.nextPtr));
	}

	Node& operator=(const Node& obj)
	{
		data = obj.data;
		nextPtr = obj.nextPtr;
		return *this;
	}
};

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Node<T>& obj) {
	stream << obj.data;
	return stream;
}

template<typename type>
class Iterator {
	template<typename k>
	friend class List;
private:
	Node<type>* current_node;

public:
	Iterator(Node<type>& node) : current_node(&node) {}
	Iterator(Node<type>* node) : current_node(node) {}
	Iterator(const Iterator<type>& obj) : current_node(obj.current_node) {}



	Iterator& operator++() {
		if (current_node != nullptr) { current_node = current_node->nextPtr; }
		else { throw std::out_of_range("Invalid iterator!"); }
		return *this;
	}
	const Iterator operator++(int) {
		if (current_node == nullptr) throw std::out_of_range("Invalid iterator!");
		Iterator<type> it(*this);
		++(*this);
		return it;
	}

	bool operator==(const Iterator<type>& obj) const noexcept {
		return current_node == obj.current_node;
	}
	bool operator!=(const Iterator<type>& obj) const noexcept {
		return current_node != obj.current_node;
	}

	type& operator*() {
		return current_node->data;
	}
	type& operator*() const {
		return current_node->data;
	}

	type* operator->() {
		return &(current_node->data);
	}
	const type* operator->() const {
		return &(current_node->data);
	}

};


template<typename T>
class List
{
private:
	int size;
	Node<T>* firstNode;
	Node<T>* lastNode;
public:
	List(int _size);
	List(const List<T>& obj);
	List();
	~List();
	Node<T>* getNode(int _n) const;
	void pushBack(T data);
	void deleteNode(int _n);;
	void deleteNode(Iterator<T> it);
	Iterator<T> begin() const { return Iterator<T>(firstNode); }
	Iterator<T> end() const { return nullptr; }
};

template<typename T>
List<T>::List(int _size)
{
	size = _size;
	firstNode = new Node<T>;
	Node<T>* oldNode = firstNode;
	for (int i = 1; i < size; i++)
	{
		Node<T>* newNode = new Node<T>;
		oldNode->nextPtr = newNode;
		oldNode = newNode;
	}
	oldNode->nextPtr = nullptr;
	lastNode = oldNode;
}

template<typename T>
List<T>::List(const List<T>& obj)
{
	size = 0;
	firstNode = new Node<T>;
	for (auto it = obj.begin(); it != obj.end(); ++it)
	{
		pushBack(*it);
	}
}

template<typename T>
List<T>::List() :List<T>::List(0)
{}

template<typename T>
List<T>::~List()
{
	Node<T>* nextNode = firstNode->nextPtr;
	delete firstNode;
	for (int i = 1; i < size; i++)
	{
		Node<T>* currentNode = nextNode;
		nextNode = nextNode->nextPtr;
		delete currentNode;
	}
}

template<typename T>
Node<T>* List<T>::getNode(int _n) const
{
	if (_n >= size)
	{
		throw std::out_of_range("Wrong index");
	}
	Node<T>* searchNode = firstNode;
	for (int i = 0; i < _n; i++)
	{
		searchNode = searchNode->nextPtr;
	}
	return searchNode;
}

template<typename T>
void List<T>::pushBack(T data)
{
	if (size != 0)
	{
		Node<T>* newNode = new Node<T>;
		lastNode->nextPtr = newNode;
		newNode->data = data;
		newNode->nextPtr = nullptr;
		lastNode = newNode;
	}
	else
	{
		firstNode->data = data;
		firstNode->nextPtr = nullptr;
		lastNode = firstNode;
	}
	size++;
}

template<typename T>
void List<T>::deleteNode(int _n)
{
	if (_n >= size)
	{
		throw std::out_of_range("Wrong index");
	}
	if (_n == 0)
	{
		if (size > 1)
		{
			Node<T>* eraseNode = firstNode;
			firstNode = firstNode->nextPtr;
			delete eraseNode;
		}
	}
	else 
	{
		Node<T>* searchNode = firstNode;
		for (int i = 0; i < _n - 1; i++)
		{
			searchNode = searchNode->nextPtr;
		}
		Node<T>* eraseNode = searchNode->nextPtr;
		searchNode->nextPtr = eraseNode->nextPtr;
		delete eraseNode;
	}
	size--;
}

template<typename T>
void List<T>::deleteNode(Iterator<T> it_)
{
	int n = 0;
	auto it = begin();
	for (; it != it_ && it != end(); ++it)
	{
		n++;
	}
	if (n != size)
	{
		deleteNode(n);
	}
	else
	{
		throw std::exception("Wrong Iterator");
	}
}


