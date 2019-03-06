#include "DoublyList.h"
void print(const DoublyList& list) {
	cout << "Forward : ";
	list.print();

	cout << "\nBackward: ";
	list.printReverse();
	cout << endl << endl;
}

int main() {
	DoublyList list1;

	list1.insertBack("A");
	list1.insertBack("B");
	list1.insertBack("B");
	list1.insertBack("B");
	list1.insertBack("C");

	// Insert Back
	cout << string(50, '-') << endl;
	cout << "Test: Insert Back" << endl;
	print(list1);

	// Insert Front
	cout << string(50, '-') << endl;
	list1.insertFront("9");
	list1.insertFront("8");
	cout << "Test: Insert Front" << endl;
	print(list1);

	// Insert At (1)
	cout << string(50, '-') << endl;
	list1.insertAt("H", 1);
	cout << "Test: Insert At (1)" << endl;
	print(list1);


	// removeAt(1)
	cout << string(50, '-') << endl;
	list1.removeAt(4);
	cout << "Test: removeAt(1)" << endl;
	print(list1);

	// removeFirst()
	cout << string(50, '-') << endl;
	list1.removeFirst();
	cout << "Test: removeFirst()" << endl;
	print(list1);

	// removeLast()
	cout << string(50, '-') << endl;
	list1.removeLast();
	cout << "Test: removeLast()" << endl;
	print(list1);


	// Insert Back
	cout << string(50, '-') << endl;
	cout << "Insert Back (6-9)" << endl;
	list1.insertBack("5");
	list1.insertBack("6");
	list1.insertBack("7");
	list1.insertBack("8");	
	print(list1);

	
	// Insert Before
	DoublyList testInsertBeforeList;
	cout << string(50, '-') << endl;
	cout << "insertBefore, insert 'S' before the second node" << endl;
	Node* node = testInsertBeforeList.insertBefore("S", testInsertBeforeList.getLast());
	print(testInsertBeforeList);

	// Insert Before
	cout << string(50, '-') << endl;
	cout << "insertBefore, insert 'S' before the second node" << endl;
	Node* node2 = testInsertBeforeList.insertBefore("J", node);
	print(testInsertBeforeList);

	// remove Node
	cout << string(50, '-') << endl;
	cout << "remove, the second node (remove 'S')" << endl;
	testInsertBeforeList.remove(node);
	print(testInsertBeforeList);

	// Swap Ends
	cout << string(50, '-') << endl;
	cout << "Test: swapEnds(). Many-elements list" << endl;
	list1.swapEnds();
	print(list1);

	// Create list2
	cout << string(50, '-') << endl;
	cout << "Create list2 that has 2 elements: 4, 5" << endl;
	DoublyList list2;
	list2.insertFront("5");
	list2.insertFront("4");
	print(list2);

	// Swap Ends
	cout << string(50, '-') << endl;
	cout << "Test: swapEnds(). Two-elements list" << endl;
	list2.swapEnds();
	print(list2);


	// swapValues
	cout << string(50, '-') << endl;
	cout << "Test: swapValues(0, 1). Two-elements list" << endl;
	list2.swapValues(0, 1);
	print(list2);

	// swapValues
	cout << string(50, '-') << endl;
	cout << "Test: swapValues(3, 5). Many-elements list" << endl;
	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	print(list1);
	cout << string(10, '-') << "After" << string(10, '-') << endl;
	list1.swapValues(3, 5);
	print(list1);

	// swapNodes
	cout << string(50, '-') << endl;
	cout << "Test: swapNodes(0, 1).  Two-elements list" << endl;
	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	print(list2);
	cout << string(10, '-') << "After" << string(10, '-') << endl;
	list2.swapNodes(0, 1);
	print(list2);

	// swapNodes
	cout << string(50, '-') << endl;
	cout << "Test: swapNodes(0, 1).  Many-elements list" << endl;
	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	print(list1);
	cout << string(10, '-') << "After" << string(10, '-') << endl;
	list1.swapNodes(2, 4);
	print(list1);


	// swapNodes
	cout << string(50, '-') << endl;
	cout << "Test: swapNodes(Node*, Node*).  Many-elements list" << endl;
	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	print(list1);
	cout << string(10, '-') << "After" << string(10, '-') << endl;
	list1.swapNodes(list1.getFirst(), list1.getLast());
	print(list1);


	// remove data
	cout << string(50, '-') << endl;
	cout << "Test: remove('B')" << endl;
	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	print(list1);
	cout << string(10, '-') << "After" << string(10, '-') << endl;
	list1.remove("B");
	print(list1);


	// reverse
	cout << string(50, '-') << endl;
	cout << "Test: reverse() the list" << endl;
	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	print(list1);
	cout << string(10, '-') << "After" << string(10, '-') << endl;
	list1.reverse();
	print(list1);


	// moveFirst3NodesToTheEnd()
	cout << string(50, '-') << endl;
	cout << "Test: moveFirst3NodesToTheEnd()" << endl;
	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	print(list1);
	cout << string(10, '-') << "After" << string(10, '-') << endl;
	list1.moveFirst3NodesToTheEnd();
	print(list1);

	system("pause");
	return 0;
}