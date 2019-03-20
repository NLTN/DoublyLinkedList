#include "HelperFunctions.h"
#include "DoublyList.h"

int main() {
	cout << "=========================" << endl;
	cout << static_cast<void*>(nullptr) << endl;

	//	system("Pause");

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
	test_swapEnds();

	// swapValues
	test_swapValues_byIndex();

	// swapNodes
	test_swapNodes_byIndex();

	// swapNodes
	test_swapNodes_FirstAndLast();
	test_swapNodes_2ndAnd3rd();

	// remove data
	test_remove(list1);

	// reverse
	test_reverse(list1);

	// moveFirst3NodesToTheEnd
	test_moveFirst3NodesToTheBack(list1);

	// moveLast3NodesToTheFront
	test_moveLast3NodesToTheFront(list1);

	// moveSecondToBack
	test_moveSecondToBack();

	// swapFirsts
	test_swapFirsts();

	// swapLasts
	test_swapLasts();

	// swapSecondAndLast
	test_swapSecondAndLast();

	// swapSecondAndPrevLast
	test_swapSecondAndPrevLast();

	// swapValuesFirstAndLast
	test_swapValuesFirstAndLast();

	// copyValuesFromObjToObj
	test_copyValuesFromObjToObj();

	system("pause");
	return 0;
}

