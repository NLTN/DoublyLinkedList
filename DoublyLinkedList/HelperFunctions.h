/*
	Nguyen, Nguyen

	March 20, 2019

	Playing  with Doubly Linked List
*/

#pragma once
#include "DoublyList.h"
void printHeader(const string& text)
{
	cout << string(50, '-') << endl;
	cout << text << endl;
}

void printList(const DoublyList& list)
{
	cout << "   Forward : ";
	list.print();

	cout << "\n   Backward: ";
	list.printReverse();

	cout << "\n   Count = " << list.getCount();

	cout << endl << endl;
}

void resetList(DoublyList& list1)
{
	list1.destroyList();

	list1.insertBack("A");
	list1.insertBack("B");
	list1.insertBack("C");
	list1.insertBack("D");
	list1.insertBack("E");
}

void test_swapEnds()
{
	DoublyList list1;
	resetList(list1);

	printHeader("Test: swapEnds(3, 5)");

	list1.swapEnds();
	printList(list1);
}

void test_swapValues_byIndex()
{
	DoublyList list1;
	resetList(list1);

	printHeader("Test: swapValues(3, 5)");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);

	cout << string(10, '-') << "After" << string(10, '-') << endl;
	list1.swapValues(3, 5);
	printList(list1);
}

void test_swapNodes_byIndex()
{
	DoublyList list1;
	resetList(list1);

	printHeader("Test: swapNodes by index (2, 4)");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);

	cout << string(10, '-') << "After" << string(10, '-') << endl;
	list1.swapNodes(2, 4);
	printList(list1);
}

void test_swapNodes_FirstAndLast()
{
	DoublyList list1;
	resetList(list1);

	printHeader("Test: swapNodes(Node*, Node*). first & last");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);

	cout << string(10, '-') << "After" << string(10, '-') << endl;
	list1.swapNodes(list1.getFirst(), list1.getLast());
	printList(list1);
}

void test_swapNodes_2ndAnd3rd()
{
	DoublyList list1;
	resetList(list1);

	printHeader("Test: swapNodes(Node*, Node*). 2nd & 3rd");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);

	cout << string(10, '-') << "After" << string(10, '-') << endl;
	list1.swapNodes(list1.getFirst()->getNext(), list1.getFirst()->getNext()->getNext());
	printList(list1);
}

void test_remove(DoublyList& list1)
{
	printHeader("Test: remove('B')");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);

	cout << string(10, '-') << "After" << string(10, '-') << endl;
	list1.remove("B");
	printList(list1);
}

void test_reverse(DoublyList& list1)
{
	printHeader("Test: reverse() the list");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);

	list1.reverse();

	cout << string(10, '-') << "After" << string(10, '-') << endl;
	printList(list1);
}

void test_moveFirst3NodesToTheBack(DoublyList& list1)
{
	resetList(list1);

	printHeader("Test: moveFirst3NodesToTheEnd()");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);

	list1.moveFirst3NodesToTheBack();

	cout << string(10, '-') << "After" << string(10, '-') << endl;
	printList(list1);
}

void test_moveLast3NodesToTheFront(DoublyList& list1)
{
	resetList(list1);

	printHeader("Test: moveLast3NodesToTheFront()");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);

	list1.moveLast3NodesToTheFront();

	cout << string(10, '-') << "After" << string(10, '-') << endl;
	printList(list1);
}

void test_moveSecondToBack()
{
	DoublyList list1;
	resetList(list1);

	printHeader("Test: moveSecondToBack()");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);

	list1.moveSecondToBack();

	cout << string(10, '-') << "After" << string(10, '-') << endl;
	printList(list1);
}

void test_swapFirsts()
{
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

void test_swapLasts()
{
	DoublyList list1;
	resetList(list1);

	DoublyList list2;
	list2.insertBack("X");
	//list2.insertBack("Y");

	printHeader("Test: swapFirsts(other)");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	cout << "List 1 " << endl;
	printList(list1);
	cout << "List 2 " << endl;
	printList(list2);

	list1.swapLasts(list2);

	cout << string(10, '-') << "After" << string(10, '-') << endl;
	cout << "List 1 " << endl;
	printList(list1);
	cout << "List 2 " << endl;
	printList(list2);
}

void test_swapSecondAndLast()
{
	DoublyList list1;
	resetList(list1);

	printHeader("Test: swapSecondAndLast()");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);

	list1.swapSecondAndLast();

	cout << string(10, '-') << "After" << string(10, '-') << endl;
	printList(list1);
}

void test_swapSecondAndPrevLast()
{
	DoublyList list2;
	resetList(list2);

	DoublyList list1;
	list1 = list2;

	printHeader("Test: swapSecondAndPrevLast()");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);

	list1.swapSecondAndPrevLast();

	cout << string(10, '-') << "After" << string(10, '-') << endl;
	printList(list1);
}

void test_swapValuesFirstAndLast()
{
	DoublyList list1;
	resetList(list1);

	DoublyList list2;
	list2.insertBack("X");
	//list2.insertBack("Y");

	printHeader("Test: swapValuesFirstAndLast(other)");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	cout << "List 1 " << endl;
	printList(list1);
	cout << "List 2 " << endl;
	printList(list2);

	list1.swapValuesFirstAndLast(list2);

	cout << string(10, '-') << "After" << string(10, '-') << endl;
	cout << "List 1 " << endl;
	printList(list1);
	cout << "List 2 " << endl;
	printList(list2);
}

void test_copyValuesFromObjToObj()
{
	DoublyList list1;
	list1.insertBack("1");
	list1.insertBack("2");
	list1.insertBack("3");
	list1.insertBack("4");

	DoublyList list2;
	list2.insertBack("11");
	list2.insertBack("22");
	list2.insertBack("33");

	vector<string> v1{ "10", "20", "30", "40", "50" };

	printHeader("Test: copyValuesFromObjToObj(vector, other)");

	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	cout << "List 1 " << endl;
	printList(list1);
	cout << "List 2 " << endl;
	printList(list2);

	list1.copyValuesFromObjToObj(v1, list2);

	cout << string(10, '-') << "After" << string(10, '-') << endl;
	cout << "List 1 " << endl;
	printList(list1);
	cout << "List 2 " << endl;
	printList(list2);
}