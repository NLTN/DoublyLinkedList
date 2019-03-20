#pragma once
#include <string>
#include <iostream>
#include <vector> 

using namespace std;

class Node {
private:
	string data;
	Node* prev;
	Node* next;

public:
	Node(string newData, Node* newPrev, Node* newNext) : data(newData), prev(newPrev), next(newNext) {};
	string getData() const { return data; }
	void setData(string value) { data = value; }

	Node* getPrev() const { return prev; }
	Node* getNext() const { return next; }

	void setPrev(Node* node) { prev = node; }
	void setNext(Node* node) { next = node; }
};

class DoublyList {
private:
	Node* first;
	Node* last;
	int count;

public:
	// Constructor & Destructor
	DoublyList() : count(0) {};

	// The BIG THREE
	DoublyList(const DoublyList& other) : count(0) {
		if (other.count == 1)
			insertBack(other.first->getData());
		else if (other.count > 1) {
			Node* current = other.first;
			while (current != nullptr) {
				insertBack(current->getData());
				current = current->getNext();
			}
		}
	}

	// The BIG THREE
	~DoublyList() { destroyList(); };

	// Overloaded Operators
	// The BIG THREE
	DoublyList& operator=(const DoublyList& other) {
		if (this == &other)
			cerr << "Self assigment" << endl;
		else {
			destroyList();
			count = 0;

			if (other.count == 1)
				insertBack(other.first->getData());
			else if (other.count > 1) {
				Node* current = other.first;
				while (current != nullptr) {
					insertBack(current->getData());
					current = current->getNext();
				}
			}
		}

		return *this;
	}

	// Getters 
	Node* getFirst() const { return first; };
	Node* getLast() const { return last; };
	int getCount() const { return count; };

	friend ostream& operator<<(ostream& out, const DoublyList& list) {
		if (list.first != nullptr) {
			if (list.count == 1)
				out << list.first->getData();
			else {
				Node* current = list.first;
				while (current != nullptr) {
					out << current->getData() << ' ';
					current = current->getNext();
				}
			}
		}

		return out;
	}

	void destroyList();
	void print() const;
	void printReverse() const;
	void insertFront(const string& newData);
	void insertBack(const string& newData);
	bool insertAt(const string& newData, int index);
	Node* insertBefore(const string& newData, Node* nextNode);
	void reverse();
	bool remove(const string& data);
	bool remove(Node* node);
	bool removeAt(int index);
	bool removeFirst();
	bool removeLast();
	void swapEnds();
	void swapNodes(int node1Index, int node2Index);
	void swapNodes(Node* node1, Node* node2);
	void swapValues(int index1, int index2) const;

	////////// OTHERS //////////
	void moveFirst3NodesToTheBack();
	void moveLast3NodesToTheFront();
	void moveSecondToBack();

	// Swap the first nodes between two objects
	void swapFirsts(DoublyList& other);
	void swapLasts(DoublyList& other);
	void swapSecondAndLast();
	void swapSecondAndPrevLast(); // Assumption: The list has at least 4 elements
	void swapValuesFirstAndLast(DoublyList& other);
	void copyValuesFromObjToObj(const vector<string>& v, DoublyList& other);
};