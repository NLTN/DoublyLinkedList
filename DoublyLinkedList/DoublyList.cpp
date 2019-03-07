/**
	Nguyen, Nguyen
*/

#include "DoublyList.h"

void DoublyList::destroyList() {
	if (first != nullptr) {
		Node* temp;

		while (first != nullptr) {
			temp = first;
			first = first->getNext();
			delete temp;
		}

		temp = nullptr;
		last = nullptr;
		count = 0;
	}
}

void DoublyList::print() const {
	if (first != nullptr) {
		if (count == 1)
			cout << first->getData();
		else {
			Node* current = first;
			while (current != nullptr) {
				cout << current->getData() << ' ';
				current = current->getNext();
			}
		}
	}
}

void DoublyList::printReverse() const {
	if (first != nullptr) {
		if (count == 1)
			cout << first->getData();
		else {
			Node* current = last;
			while (current != nullptr) {
				cout << current->getData() << ' ';
				current = current->getPrev();
			}
		}
	}
}

void DoublyList::insertFront(const string& newData) {
	if (first == nullptr) {
		first = new Node(newData, nullptr, nullptr);
		last = first;
	}
	else {
		Node* node = new Node(newData, nullptr, first);
		first->setPrev(node);
		first = node;
	}

	++count; // Update the count
}

void DoublyList::insertBack(const string& newData) {
	if (first == nullptr) {
		first = new Node(newData, nullptr, nullptr);
		last = first;
	}
	else {
		Node* node = new Node(newData, last, nullptr);
		last->setNext(node);
		last = node;
	}

	++count; // Update the count
}

bool DoublyList::insertAt(const string& newData, int index) {
	// Checking for Out of Bound
	if (index < 0 || index > count) {
		cerr << "Out of bound. Can not insert" << endl;
		return false;
	}

	// Case 1: Insert front
	if (index == 0) {
		insertFront(newData);
	}
	// Case 2: Insert back
	else if (index == count) {
		insertBack(newData);
	}
	// Case 3: Insert somewhere in the middle
	else {
		int counter(0);
		Node* current = first;

		// Go to the previous node
		while (counter < index - 1) {
			current = current->getNext();
			++counter;
		}

		// Create a node
		Node* node = new Node(newData, current, current->getNext());

		current->getNext()->setPrev(node);
		current->setNext(node);
	}

	++count; // Update the count
	return true;
}

Node* DoublyList::insertBefore(const string& newData, Node* nextNode) {
	++count; // Update the count

	// Case 1: The list is empty
	if (first == nullptr) {
		first = new Node(newData, nullptr, nullptr);
		last = first;

		return first;
	}
	// Other Cases
	else {
		Node* prevNode = nextNode->getPrev();
		Node* node = new Node(newData, prevNode, nextNode);

		if (nextNode != nullptr)
			nextNode->setPrev(node);
		else
			last = node;

		if (prevNode != nullptr)
			prevNode->setNext(node);
		else
			first = node;

		return node;
	}
}

void DoublyList::reverse() {
	if (first == nullptr) {
		cerr << "The list is empty" << endl;
	}
	else if (count == 1) {
		cerr << "No need to reverse. Only one element in the list." << endl;
	}
	else if (count == 2) {
		swapEnds();
	}
	else {
		Node* temp;
		Node* frontCurrent = first;
		Node* backCurrent = last;

		int i = 1;
		int half = count / 2;

		while (i++ <= half) {
			swapNodes(frontCurrent, backCurrent);

			// Move next
			temp = frontCurrent->getPrev();
			frontCurrent = backCurrent->getNext();
			backCurrent = temp;
		}
	}
}

bool DoublyList::remove(const string& data) {
	// Case 1: The list is empty
	if (first == nullptr) {
		cerr << "The list is empty" << endl;
		return false;
	}
	// Case 2: The list has one element
	else if (count == 1) {
		if (first->getData() == data) {
			delete first;
			first = last = nullptr;
		}
	}
	else {
		// A temp pointer. Start from the 2nd element
		Node* current = first->getNext();

		// Go to the end
		while (current != nullptr) {
			if (current->getData() == data) {
				Node* temp = current;
				Node* prevNode = current->getPrev();
				Node* nextNode = current->getNext();

				// Link the previous node to the next
				if (prevNode != nullptr)
					prevNode->setNext(nextNode);
				else
					first = nextNode;

				// Link the next node to the previous
				if (nextNode != nullptr)
					nextNode->setPrev(prevNode);
				else
					last = prevNode;

				// Move current to the next node
				current = current->getNext();

				// Delete
				delete temp;
				temp = nullptr;
			}
			else
			{
				// Move next
				current = current->getNext();
			}
		}
	}

	--count; // Update the count
}

bool DoublyList::remove(Node* node) {
	// Case 1: The list is empty or node == null
	if (node == nullptr)
		return false;
	// Case 2: The list has one element
	else if (count == 1) {
		delete node;
		node = nullptr;
		first = last = nullptr;
	}
	// Case 3: The list has more than one element
	else {
		// Link the previous node to the next
		if (node->getPrev() != nullptr)
			node->getPrev()->setNext(node->getNext());
		else {
			node->getNext()->setPrev(nullptr);
			first = node->getNext();
		}

		// Link the next node to the previous
		if (node->getNext() != nullptr)
			node->getNext()->setPrev(node->getPrev());

		else {
			node->getPrev()->setNext(nullptr);
			last = node->getPrev();
		}

		// Delete node
		delete node;
		node = nullptr;
	}

	--count; // Update the count
}

bool DoublyList::removeAt(int index) {
	// Check if out of bound
	if (index < 0 || index >= count) {
		cerr << "Out of bound" << endl;
		return false;
	}

	// Case 1: Removing the first node
	if (index == 0) {
		Node* temp = first; // A temp pointer
		first = first->getNext(); // Point to the next node
		first->setPrev(nullptr);
		delete temp; // Delete
		temp = nullptr;
	}
	// Case 2: Removing the last node
	else if (index == count - 1) {
		Node* temp = last; // A temp pointer
		last = last->getPrev(); // Point to the previous node
		last->setNext(nullptr);
		delete temp; // Delete
		temp = nullptr;
	}
	// Case 3: Removing a node in the between
	else {
		int counter = 0;
		Node* current = first;

		// Go to the node that needs to be deleted.
		while (counter < index) {
			current = current->getNext();
			++counter;
		}

		// Link the previous to the next
		current->getPrev()->setNext(current->getNext());

		// Link the next to the previous
		current->getNext()->setPrev(current->getPrev());

		// Delete the current pointer
		delete current;
		current = nullptr;
	}

	--count; // Update the count
	return true;
}

bool DoublyList::removeFirst() {
	if (first == nullptr) {
		cerr << "The list is empty" << endl;
		return false;
	}
	else {
		Node* temp = first;
		first = first->getNext();
		first->setPrev(nullptr);
		delete temp;
		temp = nullptr;
	}

	--count; // Update the count
	return true;
}

bool DoublyList::removeLast() {
	if (first == nullptr) {
		cerr << "The list is empty" << endl;
		return false;
	}
	else {
		Node* temp = last;
		last = last->getPrev();
		last->setNext(nullptr);
		delete temp;
		temp = nullptr;
	}

	--count; // Update the count
	return true;
}

void DoublyList::swapEnds() {
	if (first == nullptr) {
		cerr << "The list is empty" << endl;
	}
	else if (first == last) {
		cerr << "There is only one element in the list." << endl;
	}
	else if (count == 2) {
		last->setNext(first);
		first->setPrev(last);

		Node* temp = first;
		first = last;
		last = temp;

		first->setPrev(nullptr);
		last->setNext(nullptr);
	}
	else {
		first->setPrev(last->getPrev());
		last->setNext(first->getNext());

		Node* temp = first;
		first = last;
		last = temp;

		first->setPrev(nullptr);
		last->setNext(nullptr);

		first->getNext()->setPrev(first);
		last->getPrev()->setNext(last);
	}
}

void DoublyList::swapNodes(int node1Index, int node2Index) {
	if (node1Index < 0 || node2Index < 0 ||
		node1Index >= count || node2Index >= count)
	{
		cerr << "Invalid index" << endl;
	}
	else if (node1Index == node2Index)
	{
		cerr << "No need to swap the same element" << endl;
	}
	else if (count == 2)
	{
		swapEnds();
	}
	else
	{
		if (node1Index > node2Index)
		{
			int temp = node1Index;
			node1Index = node2Index;
			node2Index = temp;
		}

		int i = 0; // temp index

		// Go to node #1
		Node* node1 = first;
		while (i < node1Index)
		{
			node1 = node1->getNext();
			++i;
		}

		// Go to node #2
		Node* node2 = node1;
		while (i < node2Index)
		{
			node2 = node2->getNext();
			++i;
		}

		// Update node1 & node2
		Node* temp = node1->getNext();
		node1->setNext(node2->getNext());
		node2->setNext(temp);

		if (node1->getNext() != nullptr) {
			node1->getNext()->setPrev(node1);
		}

		if (node2->getNext() != nullptr) {
			node2->getNext()->setPrev(node2);
		}

		temp = node1->getPrev();
		node1->setPrev(node2->getPrev());
		node2->setPrev(temp);

		if (node1->getPrev() != nullptr) {
			node1->getPrev()->setNext(node1);
		}

		if (node2->getPrev() != nullptr) {
			node2->getPrev()->setNext(node2);
		}

		// Upadte *First and *Last
		if (node2->getPrev() == nullptr) {
			first = node2;
		}

		if (node1->getNext() == nullptr) {
			last = node1;
		}
	}
}
void DoublyList::swapNodes(Node* node1, Node* node2) {
	Node* temp; // a temp pointer

	// Swap the next pointers of node1 & node2
	temp = node1->getNext();
	node1->setNext(node2->getNext());
	node2->setNext(temp);

	// Update the previous pointer of the nearby nodes
	if (node1->getNext() != nullptr)
		node1->getNext()->setPrev(node1);
	else
		last = node1;

	if (node2->getNext() != nullptr)
		node2->getNext()->setPrev(node2);
	else
		last = node2;

	// Swap the previous pointers of node1 & node2
	temp = node1->getPrev();
	node1->setPrev(node2->getPrev());
	node2->setPrev(temp);

	// Update the next pointers of the nearby nodes
	if (node1->getPrev() != nullptr)
		node1->getPrev()->setNext(node1);
	else
		first = node1;

	if (node2->getPrev() != nullptr)
		node2->getPrev()->setNext(node2);
	else
		first = node2;
}

void DoublyList::swapValues(int node1Index, int node2Index) const {
	if (node1Index < 0 || node2Index < 0 ||
		node1Index >= count || node2Index >= count)
	{
		cerr << "Invalid index" << endl;
	}
	else if (node1Index == node2Index)
	{
		cerr << "Swapping the same element" << endl;
	}
	else if (count == 2)
	{
		string temp = first->getData();
		first->setData(first->getNext()->getData());
		first->getNext()->setData(temp);
	}
	else
	{
		if (node1Index > node2Index)
		{
			int temp = node1Index;
			node1Index = node2Index;
			node2Index = temp;
		}

		int i = 0; // temp index

		// Go the node #1
		Node* node1 = first;
		while (i < node1Index)
		{
			node1 = node1->getNext();
			++i;
		}

		// Go the node #2
		Node* node2 = node1;
		while (i < node2Index)
		{
			node2 = node2->getNext();
			++i;
		}

		// Swap values of elements #1 and #2
		string temp = node1->getData();
		node1->setData(node2->getData());
		node2->setData(temp);
	}
}

////////// OTHERS //////////
void DoublyList::moveFirst3NodesToTheBack() {
	// Get the new last node
	Node* newLast = first->getNext()->getNext();

	// Make a Circular list
	last->setNext(first);
	first->setPrev(last);

	// Update first & last
	first = newLast->getNext(); // connect to the 4th node
	last = newLast;

	// Update first's previous & last's next
	first->setPrev(nullptr);
	last->setNext(nullptr);
}

void DoublyList::moveLast3NodesToTheFront() {
	// Get the new first node
	Node* newFirst = last->getPrev()->getPrev();

	// Make a Circular list
	last->setNext(first);
	first->setPrev(last);

	// Update first & last
	first = newFirst;
	last = newFirst->getPrev();

	// Update first's previous & last's next
	first->setPrev(nullptr);
	last->setNext(nullptr);
}

void DoublyList::swapFirsts(DoublyList& other) {
	// Link the second nodes to the first nodes
	if (first->getNext() != nullptr) {
		first->getNext()->setPrev(other.first);
	}

	if (other.first->getNext() != nullptr) {
		other.first->getNext()->setPrev(first);
	}

	// Link the first nodes to the second nodes
	Node* temp = first->getNext();
	first->setNext(other.first->getNext());
	other.first->setNext(temp);

	// Swap first pointers DoublyList
	temp = first;
	first = other.first;
	other.first = temp;

	// Update the lasts if needed
	if (count == 1)
		last = first;
	if (other.count == 1)
		other.last = other.first;
}

void DoublyList::swapLasts(DoublyList& other) {
	// Link the previous nodes to new last nodes
	if (last->getPrev() != nullptr) {
		last->getPrev()->setNext(other.last);
	}

	if (other.last->getPrev() != nullptr) {
		other.last->getPrev()->setNext(last);
	}

	// Link the last nodes to the previous nodes
	Node* temp = last->getPrev();
	last->setPrev(other.last->getPrev());
	other.last->setPrev(temp);

	// Swap last pointers
	temp = last;
	last = other.last;
	other.last = temp;

	// Update the firsts if needed
	if (count == 1)
		first = last;

	if (other.count == 1)
		other.first = other.last;
}