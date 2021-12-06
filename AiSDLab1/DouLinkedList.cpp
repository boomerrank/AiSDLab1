#include "DuoLinkedList.h"
#include <stdexcept>

//Overload operator "<<" for class "DouLinkedList"
std::ostream& operator<<(std::ostream& stream, DouLinkedList& list)
{
	if (list.isEmpty()) {
		return stream;
	}
	Node* current = list.head;
	stream << current->getData();
	current = current->getNext();
	while (current != nullptr) {
		stream << ' ' << current->getData();
		current = current->getNext();
	}
	return stream;
}

//Set next Node in the list
void Node::setNext(Node* next) {
	this->next = next;
}

//Set previous Node in the list
void Node::setPrevious(Node* previous) {
	this->previous = previous;
}

//Set data to the Node
void Node::setData(int data) {
	this->data = data;
}

//Get pointer to the next Node
Node* Node::getNext() {
	return next;
}

//Get pointer to the previous Node
Node* Node::getPrevious() {
	return previous;
}

//Get data from the Node
int Node::getData() {
	return data;
}

//Push Node to the end
void DouLinkedList::push_back(const int data) {
	Node* current = new Node(data);
	if (head == nullptr) {
		head = current;
	}
	if (tail != nullptr) {
		tail->setNext(current);
	}
	current->setPrevious(tail);
	current->setNext(nullptr);
	tail = current;
}

//Push Node to the front
void DouLinkedList::push_front(const int data) {
	Node* current = new Node(data);
	if (tail == nullptr) {
		tail = current;
	}
	if (head != nullptr) {
		head->setPrevious(current);
	}
	current->setNext(head);
	current->setPrevious(nullptr);
	head = current;
}

//Delete Node from the end
void DouLinkedList::pop_back() {
	if (this->isEmpty()) {
		return;
	}
	if (tail->getPrevious() != nullptr) {
		tail = tail->getPrevious();
		delete tail->getNext();
		tail->setNext(nullptr);
	}
	else {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
}

//Delete Node from the front
void DouLinkedList::pop_front() {
	if (this->isEmpty()) {
		return;
	}
	Node* current = head;
	if (head->getNext() != nullptr) {
		head = head->getNext();
		delete head->getPrevious();
		head->setPrevious(nullptr);
	}
	else {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
}

//Insert Node in front of Node with index size_t
void DouLinkedList::insert(int data, int size_t) {
	if (size_t < 0) {
		return;
	}
	if (head == nullptr) {
		this->push_back(data);
	}
	Node* current = head;
	int index = 1;
	while ((index < size_t) && (current->getNext() != nullptr)) {
		current = current->getNext();
		index++;
	}
	Node* newNode = new Node(data);
	newNode->setNext(current->getNext());
	newNode->setPrevious(current);
	if (current->getNext() != nullptr) {
		(newNode->getNext())->setPrevious(newNode);
	}
	else {
		tail = current;
	}
	current->setNext(newNode);
}

//Get data from the Node with index size_t
int DouLinkedList::at(int size_t) {
	if ((size_t < 0) || (size_t >= this->get_size())) {
		throw std::out_of_range("out of the list range");
	}
	Node* current = head;
	int index = 0;
	while (index < size_t) {
		current = current->getNext();
		index++;
	}
	return current->getData();
}

//Delete Node with index size_t
void DouLinkedList::remove(int size_t) {
	if ((head == nullptr) || (size_t < 0)) {
		return;
	}
	Node* current = head;
	int index = 0;
	while (index < size_t) {
		if (current->getNext() == nullptr) {
			return;
		}
		current = current->getNext();
		index++;
	}
	(current->getPrevious())->setNext(current->getNext());
	if (current->getNext() != nullptr) {
		(current->getNext())->setPrevious(current->getPrevious());
	}
	else {
		tail = current->getPrevious();
	}
	delete current;
}

//Get size of the list
int DouLinkedList::get_size() {
	if (head == nullptr) {
		return 0;
	}
	Node* current = head;
	int size = 1;
	while (current->getNext() != nullptr) {
		current = current->getNext();
		size++;
	}
	return size;
}

//Clear the list
void DouLinkedList::clear() {
	if (head == nullptr) {
		return;
	}
	Node* current = head;
	while (current->getNext() != nullptr) {
		current = current->getNext();
		delete current->getPrevious();
	}
	delete current;
	head = nullptr;
	tail = nullptr;
}

//Set data to the Node with index size_t
void DouLinkedList::set(int size_t, int data) {
	if ((head == nullptr) || (size_t < 0)) {
		return;
	}
	Node* current = head;
	int index = 0;
	while (index < size_t) {
		if (current->getNext() == nullptr) {
			return;
		}
		current = current->getNext();
		index++;
	}
	current->setData(data);
}

//Check if the list is empty
bool DouLinkedList::isEmpty() {
	return (head == nullptr);
}

//Swap two Nodes with certain indices
void DouLinkedList::swap(int index1, int index2)
{
	if ((index1 < 0) || (index2 < 0) || (index1 == index2) || (index1 > (this->get_size() - 1)) || (index2 > (this->get_size() - 1)) || (head == tail)) {
		return;
	}
	Node* current1 = head;
	Node* current2 = head;
	int index = 0;
	while (index < index1) {
		current1 = current1->getNext();
		index++;
	}
	index = 0;
	while (index < index2) {
		current2 = current2->getNext();
		index++;
	}
	int temp = current1->getData();
	current1->setData(current2->getData());
	current2->setData(temp);
}