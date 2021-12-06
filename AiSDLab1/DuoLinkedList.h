#pragma once
#include <iostream>

//Node in the DouLinkedList
class Node {
private:
	Node* next;
	Node* previous;
	int data;

public:
	//Constructor
	Node(const int data) {
		this->data = data;
		next = nullptr;
		previous = nullptr;
	}

	void setNext(Node* next); //Set next Node in the list
	
	void setPrevious(Node* previous); //Set previous Node in the list

	void setData(int data); //Set data to the Node
	
	Node* getNext(); //Get pointer to the next Node
	
	Node* getPrevious(); //Get pointer to the previous Node

	int getData(); //Get data from the Node
};

class DouLinkedList {
private:
	Node* head;
	Node* tail;

public:
	//Constructor
	DouLinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	//Destructor
	~DouLinkedList() {
		this->clear();
	}

	//Friend functions
	friend std::ostream& operator << (std::ostream& stream, DouLinkedList& list); // "<<" Overload
	
	void push_back(const int data); //Push Node to the end
	
	void push_front(const int data); //Push Node to the front

	void pop_back(); //Delete Node from the end
	
	void pop_front(); //Delete Node from the front
	
	void insert(int data, int size_t); //Insert Node in front of Node with index size_t
	
	int at(int size_t); //Get data from the Node with index size_t
	
	void remove(int size_t); //Delete Node with index size_t
	
	int get_size(); //Get size of the list
	
	void clear(); //Clear the list
	
	void set(int size_t, int data); //Set data to the Node with index size_t

	bool isEmpty(); //Check if the list is empty

	void swap(int index1, int index2); //Swap two Nodes with certain indices
};