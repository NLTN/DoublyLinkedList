#include "HelperFunctions.h"
#include "DoublyList.h"

int main() {
	DoublyList list1;
	resetList(list1);

	// Insert Back
	printHeader("Test: Insert Back");
	printList(list1);

	// Insert Front
	cout << string(50, '-') << endl;
	list1.insertFront("9");
	list1.insertFront("8");
	cout << "Test: Insert Front" << endl;
	printList(list1);

	// Insert At (1)
	cout << string(50, '-') << endl;
	list1.insertAt("H", 1);
	cout << "Test: Insert At (1)" << endl;
	printList(list1);


	// removeAt(1)
	cout << string(50, '-') << endl;
	list1.removeAt(4);
	cout << "Test: removeAt(1)" << endl;
	printList(list1);

	// removeFirst()
	cout << string(50, '-') << endl;
	list1.removeFirst();
	cout << "Test: removeFirst()" << endl;
	printList(list1);

	// removeLast()
	cout << string(50, '-') << endl;
	list1.removeLast();
	cout << "Test: removeLast()" << endl;
	printList(list1);


	// Insert Back
	cout << string(50, '-') << endl;
	cout << "Insert Back (6-9)" << endl;
	list1.insertBack("5");
	list1.insertBack("6");
	list1.insertBack("7");
	list1.insertBack("8");	
	printList(list1);

	
	// Insert Before
	DoublyList testInsertBeforeList;
	cout << string(50, '-') << endl;
	cout << "insertBefore, insert 'S' before the second node" << endl;
	Node* node = testInsertBeforeList.insertBefore("S", testInsertBeforeList.getLast());
	printList(testInsertBeforeList);

	// Insert Before
	cout << string(50, '-') << endl;
	cout << "insertBefore, insert 'S' before the second node" << endl;
	Node* node2 = testInsertBeforeList.insertBefore("J", node);
	printList(testInsertBeforeList);

	// remove Node
	cout << string(50, '-') << endl;
	cout << "remove, the second node (remove 'S')" << endl;
	testInsertBeforeList.remove(node);
	printList(testInsertBeforeList);

	// Swap Ends
	cout << string(50, '-') << endl;
	cout << "Test: swapEnds(). Many-elements list" << endl;
	list1.swapEnds();
	printList(list1);

	// Create list2
	cout << string(50, '-') << endl;
	cout << "Create list2 that has 2 elements: 4, 5" << endl;
	DoublyList list2;
	list2.insertFront("5");
	list2.insertFront("4");
	printList(list2);

	// Swap Ends
	cout << string(50, '-') << endl;
	cout << "Test: swapEnds(). Two-elements list" << endl;
	list2.swapEnds();
	printList(list2);


	// swapValues
	cout << string(50, '-') << endl;
	cout << "Test: swapValues(0, 1). Two-elements list" << endl;
	list2.swapValues(0, 1);
	printList(list2);

	// swapValues
	cout << string(50, '-') << endl;
	cout << "Test: swapValues(3, 5). Many-elements list" << endl;
	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);
	cout << string(10, '-') << "After" << string(10, '-') << endl;
	list1.swapValues(3, 5);
	printList(list1);

	// swapNodes
	cout << string(50, '-') << endl;
	cout << "Test: swapNodes(0, 1).  Two-elements list" << endl;
	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list2);
	cout << string(10, '-') << "After" << string(10, '-') << endl;
	list2.swapNodes(0, 1);
	printList(list2);

	// swapNodes
	cout << string(50, '-') << endl;
	cout << "Test: swapNodes(0, 1).  Many-elements list" << endl;
	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);
	cout << string(10, '-') << "After" << string(10, '-') << endl;
	list1.swapNodes(2, 4);
	printList(list1);


	// swapNodes
	cout << string(50, '-') << endl;
	cout << "Test: swapNodes(Node*, Node*).  Many-elements list" << endl;
	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);
	cout << string(10, '-') << "After" << string(10, '-') << endl;
	list1.swapNodes(list1.getFirst(), list1.getLast());
	printList(list1);


	// remove data
	cout << string(50, '-') << endl;
	cout << "Test: remove('B')" << endl;
	cout << string(10, '-') << "Before" << string(10, '-') << endl;
	printList(list1);
	cout << string(10, '-') << "After" << string(10, '-') << endl;
	list1.remove("B");
	printList(list1);

	// reverse
	test_reverse(list1);

	// moveFirst3NodesToTheEnd()
	test_moveFirst3NodesToTheBack(list1);

	// moveLast3NodesToTheFront()
	test_moveLast3NodesToTheFront(list1);

	// swapFirsts
	test_swapFirsts();

	// swapLasts
	test_swapLasts();


	system("pause");
	return 0;
}

