#pragma once
#include "DoublyList.h"
void printHeader(const string& text) {
	cout << string(50, '-') << endl;
	cout << text << endl;
}

void printList(const DoublyList& list) {
	cout << "Forward : ";
	list.print();

	cout << "\nBackward: ";
	list.printReverse();
	cout << endl << endl;
}

void resetList(DoublyList& list1) {
	list1.destroyList();

	list1.insertBack("A");
	list1.insertBack("B");
	list1.insertBack("C");
	list1.insertBack("D");
	list1.insertBack("E");
}

void test_reverse(DoublyList& list1) {
	printHeader("Test: reverse() the list");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);

	list1.reverse();
	
	cout << string(10, '-') << "After" << string(10, '-') << endl;
	printList(list1);
}

void test_moveFirst3NodesToTheBack(DoublyList& list1) {
	resetList(list1);

	printHeader("Test: moveFirst3NodesToTheEnd()");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);

	list1.moveFirst3NodesToTheBack();

	cout << string(10, '-') << "After" << string(10, '-') << endl;
	printList(list1);
}

void test_moveLast3NodesToTheFront(DoublyList& list1) {
	resetList(list1);

	printHeader("Test: moveLast3NodesToTheFront()");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);

	list1.moveLast3NodesToTheFront();

	cout << string(10, '-') << "After" << string(10, '-') << endl;
	printList(list1);
}

void test_swapFirsts() {
	DoublyList list1;
	resetList(list1);

	DoublyList list2;
	list2.insertBack("X");
	//list2.insertBack("Y");

	printHeader("Test: swapFirsts(other)");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);
	printList(list2);

	list1.swapFirsts(list2);

	cout << string(10, '-') << "After" << string(10, '-') << endl;
	printList(list1);
	printList(list2);
}

void test_swapLasts() {
	DoublyList list1;
	resetList(list1);

	DoublyList list2;
	list2.insertBack("X");
	//list2.insertBack("Y");

	printHeader("Test: swapFirsts(other)");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);
	printList(list2);

	list1.swapLasts(list2);

	cout << string(10, '-') << "After" << string(10, '-') << endl;
	printList(list1);
	printList(list2);
}