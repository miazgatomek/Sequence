#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <cstdlib>
#include <typeinfo>

template<typename Key,typename Info>
class Sequence {
private:

	struct Node {
		Key key;
		Info info;
		Node* nextNode = nullptr;
	};

	Node* head = nullptr;


	void printReverse(Node * temp,int position) {
		if (temp != nullptr) {
			this->printReverse(temp->nextNode, position + 1);
			std::cout << "\n(" << position << ") Key: " << temp->key << "\tInfo: " << temp->info;
		}
	}

public:

	/*
	METHODS:

	Sequence();
	Sequence(int);
	Sequence(const Sequence<Key, Info>&);
	~Sequence();
	void addNodeFront(Key, Info)
	void addNodeFixedPosition(Key, Info, int);
	void addNodeTail(Key, Info);
	void displayList();
	void displayGivenNode(int);
	void displayReverse();
	void swapNodes(int);
	void swapData(int);
	//void sortAscending();
	int returnListSize();
	void clearList();
	void removeHeadNode();
	void removeFixedNode(int);
	void removeTailNode();
	Sequence<Key, Info> &operator=(const Sequence<Key, Info>&);
	Sequence<Key,Info> &operator+=(const Sequence<Key, Info>&);
	void createRandomNodes(int);
	void giveNodes(const Sequence<Key, Info> &, int, int);
	bool containsKey(Key);
	bool checkKeyInfoType();
	bool checkKeyType();
	*/

	Sequence() {}


	Sequence(int numOfNodes) {
		
		if (this->checkKeyInfoType()) {
			this->createRandomNodes(numOfNodes);
		}
		else {
			std::cout << "\nThis constructor allows only Key, Info = int" ;
		}
	}


	Sequence(const Sequence<Key, Info> &givenList) {
		
		Node* temp = givenList.head;
		
		while (temp != nullptr) {
			this->addNodeOnTail(temp->key, temp->info);
			temp = temp->nextNode;
		}
	}


	~Sequence() {
		this->clearList();
	}


	void addNodeOnFront(Key myKey, Info myInfo) {
		
		if (!this->containsKey(myKey)) {
			return;
		}
		
		Node* newNode = new Node;

		if (this->head == nullptr) {
			newNode->key = myKey;
			newNode->info = myInfo;
			this->head = newNode;
			return;
		}
		else {
			newNode->key = myKey;
			newNode->info = myInfo;
			newNode->nextNode = this->head;
			this->head = newNode;
		}
	}


	void addNodeFixedIndex(Key myKey, Info myInfo, int position) {
		
		if (!this->containsKey(myKey)) {
			return;
		}
		else if (position == 0) {
			this->addNodeOnFront(myKey, myInfo);
			return;
		}
		else if (position >= this->returnListSize() - 1) {
			this->addNodeOnTail(myKey, myInfo);
			return;
		}

		Node * temp = this->head;
		Node * temp2;
		
		for (int i = 1; i < position; i++) {
			temp = temp->nextNode;
		}

		temp2 = temp->nextNode;

		Node * newNode = new Node;
		
		newNode->key = myKey;
		newNode->info = myInfo;
		newNode->nextNode = temp2;
		temp->nextNode = newNode;
	}


	void addNodeOnTail(Key myKey, Info myInfo) {
		
		if (!this->containsKey(myKey)) {
			return;
		}
		
		if (this->head == nullptr) {
			this->addNodeOnFront(myKey, myInfo);
			return;
		}

		Node* newNode = new Node;
		newNode->key = myKey;
		newNode->info = myInfo;
		
		Node * temp = this->head;

		while (temp->nextNode != nullptr) {
			temp = temp->nextNode;
		}

		temp->nextNode = newNode;
	}

	
	void displayList() {
		
		if (this->head == nullptr) {
			std::cout << "\nThe list is empty";
			return;
		}

		Node* temp = this->head;
		int i = 0;

		while (temp != nullptr) {
			std::cout << "\n(" << i << ") " << "Key: " << temp->key << "\tInfo: " << temp->info;
			temp = temp->nextNode;
			i++;
		}
	}

	
	void displayGivenNode(int position) {
		
		if (position >= returnListSize() || position < 0) {
			std::cout << "\nNo such node exists, passed parameter: " << position;
			return;
		}

		Node* temp = this->head;
		
		for (int i = 0; i < position; i++) {
			temp = temp->nextNode;
		}

		std::cout << "\nNode position: " << position;
		std::cout << "\nKey: " << temp->key << "\tInfo: " << temp->info;
	}


	void displayReverse() {
		if (head == nullptr) {
			std::cout << "\nThe list is empty";
			return;
		}
		this->printReverse(this->head,0);
	}


	void swapNodes(int position) {

		if (position < 0 || position >= this->returnListSize() - 1) {
			std::cout << "\nWrong parameter swapNodes()";
			return;
		}

		Node* temp1 = this->head;
		Node* temp2;
		Node* temp3;

		if (position == 0) {
			temp2 = temp1->nextNode;
			temp1->nextNode = temp2->nextNode;
			temp2->nextNode = temp1;
			this->head = temp2;
			return;
		}
		else if (position == this->returnListSize() - 2) {
			for (int i = 1; i < position; i++) {
				temp1 = temp1->nextNode;
			}

			temp2 = temp1->nextNode;
			temp3 = temp2->nextNode;

			temp1->nextNode = temp3;
			temp3->nextNode = temp2;
			temp2->nextNode = nullptr;

			return;
		}

		for (int i = 1; i < position; i++) {
			temp1 = temp1->nextNode;
		}

		temp2 = temp1->nextNode;
		temp3 = temp2->nextNode;

		temp2->nextNode = temp3->nextNode;
		temp3->nextNode = temp2;
		temp1->nextNode = temp3;
	}


	void swapData(int position) {
		if (position >= this->returnListSize() - 1) {
			std::cout << "\nWrong parameter swapData()";
			return;
		}

		Node * temp1 = this->head;
		Node * temp2;
		Key myKey;
		Info myInfo;

		for (int i = 0; i < position; i++) {
			temp1 = temp1->nextNode;
		}

		temp2 = temp1->nextNode;

		myKey = temp2->key;
		myInfo = temp2->info;
		temp2->key = temp1->key;
		temp2->info = temp1->info;
		temp1->key = myKey;
		temp1->info = myInfo;
	}


	/*void sortAscending() {

		if (!this->checkKeyInfoType()) {
			return;
		}

		int max;
		Sequence<int, int> sortedList;
		Node* temp1;
		Node* temp2 = nullptr;
		bool unsorted = true;

		while (unsorted) {
			temp1 = this->head;
			max = -1;

			while (temp1 != nullptr) {

				if (temp1->key > max && sortedList.head == nullptr) {
					temp2 = temp1;
				}
				else if (temp1->key > max && temp1->key < sortedList.head->key) {
					temp2 = temp1;
				}

				temp1 = temp1->nextNode;
			}

			sortedList.addNodeOnFront(temp2->key, temp2->info);

			if (sortedList.returnListSize() == this->returnListSize()) {
				unsorted = false;
			}
		}

		this->clearList();

		Node* temp = sortedList.head;

		while (temp != nullptr) {
			this->addNodeOnTail(temp->key, temp->info);
			temp = temp->nextNode;
		}
	}*/

	
	int returnListSize() {
		
		Node * temp = this->head;
		int listSize = 0;
		
		while (temp != nullptr) {
			listSize++;
			temp = temp->nextNode;
		}

		return listSize;
	}

	
	void clearList() {
		
		Node* temp = this->head;
		
		while (head != nullptr) {
			temp = this->head;
			this->head = this->head->nextNode;
			delete temp;
		}
	}

	
	void removeHeadNode() {
		
		if (this->head == nullptr) {
			std::cout << "\nThe list is empty";
			return;
		}
		
		Node* temp = this->head;
		this->head = this->head->nextNode;
		delete temp;
	}


	void removeFixedNode(int position) {
		
		if (position < 0) {
			std::cout << "\nPass positive integers (removeFixedNode method)";
			return;
		}
		else if (position >= this->returnListSize() - 1) {
			this->removeTailNode();
			return;
		}
		else if (position == 0) {
			this->removeHeadNode();
			return;
		}

		Node* temp = this->head;

		for (int i = 1; i < position - 1; i++) {
			temp = temp->nextNode;
		}

		Node* deleteTemp = temp->nextNode;

		temp->nextNode = deleteTemp->nextNode;
		delete deleteTemp;
	}
	

	void removeTailNode() {
		
		if (this->head == nullptr) {
			std::cout << "\nThe list is empty";
			return;
		}

		if (this->head->nextNode == nullptr) {
			delete head;
			return;
		}

		Node* temp = this->head;

		while (temp->nextNode->nextNode != nullptr) {
			temp = temp->nextNode;
		}

		delete temp->nextNode;
		temp->nextNode = nullptr;
	}

	
	Sequence<Key, Info> &operator=(const Sequence<Key,Info> &givenList) {
		
		this->clearList();
		
		Node* temp = givenList.head;
		
		while (temp != nullptr) {
			this->addNodeOnTail(temp->key, temp->info);
			temp = temp->nextNode;
		}
		
		return *this;
	}

	
	Sequence<Key, Info> &operator+=(const Sequence<Key, Info> &givenList) {
		
		Node* temp = givenList.head;
		
		while (temp != nullptr) {
			this->addNodeOnTail(temp->key, temp->info);
			temp = temp->nextNode;
		}
		
		return *this;
	}

	
	void createRandomNodes(int numberOfNodes) {
		
		if (!this->checkKeyInfoType()) {
			std::cout << "\nOnly int,int types are appropriate for createRandomNodes()";
			return;
		}

		for (int i = 0; i < numberOfNodes; i++) {
			int randomKey = rand() % 100 + 1;
			int randomInfo = rand() % 100 + 1;
			this->addNodeOnFront(randomKey, randomInfo);
		}
	}

	
	void giveNodes(const Sequence<Key, Info> &givenList, int start, int length) {
		
		Node* temp = givenList.head;
		
		for (int i = 0; i < start; i++) {
			if (temp == nullptr) {
				return;
			}
			temp = temp->nextNode;
		}

		for (int i = 0; i < length; i++) {
			if (temp == nullptr) {
				return;
			}
			this->addNodeOnTail(temp->key,temp->info);
			temp = temp->nextNode;
		}
	}

	
	bool containsKey(Key myKey) {
		
		Node* temp = this->head;
		
		while (temp != nullptr) {
			if (temp->key == myKey) {
				std::cout << "\nKey already taken: " << myKey;
				return false;
			}
			temp = temp->nextNode;
		}

		return true;
	}


	bool checkKeyInfoType() {
		if (typeid(Key) == typeid(int) && typeid(Info) == typeid(int)) {
			return true;
		}
		return false;
	}


	bool checkKeyType() {
		if (typeid(Key) == typeid(int)) {
			return true;
		}
		return false;
	}
};

/*
ADDITIONAL FUNCTIONS:

bool checkShufflevariables(int, int, int, int,int);
Sequence<Key, Info> shuffle(const Sequence<Key, Info> &, int, int, const Sequence<Key, Info> &, int, int, int);
*/

bool checkShuffleVariables(int start1, int len1, int start2, int len2, int count) {
	
	if (start1 >= 0 && len1 > 0 && start2 >= 0 && len2 > 0 && count > 0) {
		return true;
	}

	return false;
}


template<typename Key, typename Info>
Sequence<Key, Info> shuffle(const Sequence<Key, Info> &s1, int start1, int len1,
	const Sequence<Key, Info> &s2, int start2, int len2, int count) {

	Sequence<Key, Info> returnObject;

	if (!checkShuffleVariables(start1, len1, start2, len2, count)) {
		std::cout << "\nInappropriate values passed to shuffle function";
		return returnObject;
	}

	for (int i = 0; i < count; i++) {
		returnObject.giveNodes(s1, start1 + (i * len1), len1);
		returnObject.giveNodes(s2, start2 + (i * len2), len2);
	}

	return returnObject;
}


/*
TESTS:

void displayListTest();
void displayGivenNodeTest();
void addDeleteNodes();
void increaseOPeratorTest();
void equalOperatorTest();
void copyConstructorTest();
void listSizeTest();
void shuffleFunctionTest();
void addFixedPositionNodesTest();
void deleteFixedPositionTest();
void containsKeyTest();
void constructorsTest();
void checkKeyInfoTest();
void swapNodesTest();
void swapDataTest();
*/

void displayListTest() {
	
	std::cout << "\n\n\tDISPLAYING LIST TEST\n";
	
	Sequence<int, int> test(3);
	
	std::cout << "\n Displaying list normally:";
	test.displayList();

	std::cout << "\n Displaying list in reverse:";
	test.displayReverse();
	
	test.clearList();
	std::cout << "\n Displaying clear list:";
	test.displayList();
	test.displayReverse();
}


void displayGivenNodeTest() {
	
	std::cout << "\n\n\tDISPLAYING GIVEN NODE TEST\n";

	Sequence<int, int> test;

	std::cout << "\n Empty list:";
	test.displayGivenNode(1);

	std::cout << "\n Five node list:";
	test.createRandomNodes(5);

	test.displayGivenNode(0);
	test.displayGivenNode(2);
	test.displayGivenNode(4);
	test.displayGivenNode(10);
	test.displayGivenNode(-3);
}


void addDeleteNodesTest() {
	
	std::cout << "\n\n\tADDING AND DELETING NODES TEST\n";
	
	Sequence<int, int> test;
	
	test.addNodeOnFront(5, 1);
	test.addNodeOnTail(1, 5);
	test.createRandomNodes(5);
	test.createRandomNodes(-3);
	
	std::cout << "\n List expanded by all adding methods:";
	test.displayList();
	
	std::cout << "\n Checking removeHeadNode, removeTailNode";
	test.removeHeadNode();
	test.removeTailNode();
	test.displayList();
}


void increaseOperatorTest() {
	
	std::cout << "\n\n\t+= OPERATOR TEST\n";
	
	Sequence<int, int> test(3), test2(4);
	
	std::cout << "\n First list:";
	test.displayList();
	
	std::cout << "\n Second list:";
	test2.displayList();

	test += test2;
	
	std::cout << "\n Increased first list:";
	test.displayList();

	std::cout << "\n Increased by empty list:";
	test2.clearList();
	
	test += test2;
	test.displayList();
}


void equalOperatorTest() {
	
	std::cout << "\n\n\t= OPERATOR TEST\n";
	
	Sequence<int, int> test(3), test2;
	
	test2 = test;
	
	std::cout << "\n Original list:";
	test.displayList();
	
	std::cout << "\n Copied list:";
	test2.displayList();

	std::cout << "\n Copying from empty list result:";
	test.clearList();

	test2 = test;

	test2.displayList();
}


void listSizeTest() {
	
	std::cout << "\n\n\tLIST SIZE TEST\n\n";
	
	Sequence<int, int> test(3);
	
	std::cout << " Three node list:";
	std::cout << "\n" << test.returnListSize();

	std::cout << "\n Empty list:";
	test.clearList();

	std::cout << "\n" << test.returnListSize();
}


void shuffleFunctionTest() {
	
	std::cout << "\n\n\tSHUFFLE FUNCTION TEST\n";
	Sequence<int, int> s1(4),s2(5),s3;

	s3 = shuffle(s1, 0, 2, s2, 3, 2, 5);
	
	std::cout << "\n Sequence 1:";
	s1.displayList();
	
	std::cout << "\n Sequence 2:";
	s2.displayList();
	
	std::cout << "\n Shuffled sequence:";
	s3.displayList();

	s3.clearList();

	std::cout << "\n Passing wrong parameters to shuffle function:";
	s3 = shuffle(s1, 0, 0, s2, 0, 0, 0);
}


void addFixedIndexTest() {
	
	std::cout << "\n\n\tADDING NODES BY FIXED POSITION TEST\n";
	Sequence<int, int> test(3);

	std::cout << "\n Sequence 1:";
	test.displayList();
	
	std::cout << "\n Sequence 2:";
	test.addNodeFixedIndex(1,2,0);
	test.displayList();
	
	std::cout << "\n Sequence 3:";
	test.addNodeFixedIndex(3,4,2);
	test.displayList();
	
	std::cout << "\n Sequence 4:";
	test.addNodeFixedIndex(5,6,4);
	test.displayList();
}


void deleteFixedPositionTest() {
	
	std::cout << "\n\n\tDELETE NODE BY FIXED POSITION TEST\n";
	
	Sequence<int, int> test;

	std::cout << "\n Empty list:";
	test.removeFixedNode(0);
	test.removeFixedNode(-1);
	test.removeFixedNode(1);
	
	
	std::cout << "\n Five node list:";
	test.createRandomNodes(5);
	test.displayList();

	std::cout << "\n After deleting:";
	
	test.removeFixedNode(5);
	test.removeFixedNode(0);
	test.removeFixedNode(4);
	test.removeFixedNode(10);
	test.removeFixedNode(-5);

	test.displayList();
}


void containsKeyTest() {
	
	std::cout << "\n\n\tADDING NODES WITH ALREADY TAKEN KEY TEST\n";
	
	Sequence<int, int> test;

	test.addNodeOnFront(1, 1);
	test.addNodeOnFront(2, 1);
	test.addNodeOnFront(3, 1);

	std::cout << "\n Given list:";
	test.displayList();

	std::cout << "\n Adding node with already existing key:";
	test.addNodeOnFront(2,1000);
}


void constructorsTest() {
	
	std::cout << "\n\n\tCONSTRUCTORS TEST\n";

	std::cout << "\n Copy constructor:";
	Sequence<int, int> test(3);

	std::cout << "\n Original List:";
	test.displayList();

	Sequence<int, int> test2(test);

	std::cout << "\n Copied List:";
	test2.displayList();

	std::cout << "\n Creating object from an empty list:";
	test2.clearList();

	Sequence<int, int> test3(test2);

	test3.displayList();

	std::cout << "\n Sequence(int) constructor:";
	Sequence<int, double> test4(3);

	Sequence<int, int> test5(5);
	test5.displayList();
}


void checkKeyInfoTest() {

	std::cout << "\n\n\tTEMPLATE TYPES CHECKING METHODS TEST\n";

	Sequence<int, int> test1;
	Sequence<int, double> test2;
	Sequence<double, int> test3;

	test1.checkKeyType();
	test1.checkKeyInfoType();
	
	test2.checkKeyType();
	test2.checkKeyInfoType();
	
	test3.checkKeyType();
	test3.checkKeyInfoType();
}


void swapNodesTest() {
	
	std::cout << "\n\n\tNODES SWAP METHOD TEST\n";
	
	Sequence<int, int> test(5);

	std::cout << "\n Original list:";
	test.displayList();

	for (int i = 0; i < 5; i++) {
		test.swapNodes(i);
	}

	std::cout << "\n Swapped list:";
	test.displayList();
}


void swapDataTest() {

	std::cout << "\n\n\tDATA SWAP TEST\n";

	Sequence<int, int> test(6);

	std::cout << "\n Original list:";
	test.displayList();

	for (int i = 0; i < 8; i++) {
		test.swapData(i);
	}

	std::cout << "\n Swapped list:";
	test.displayList();
}


/*void sortTest() {

	std::cout << "\n\n\tSORTING TEST\n";
	
	Sequence<int, int> test(5);

	std::cout << "\n Original list:";
	test.displayList();

	std::cout << "\n Sorted list:";
	test.sortAscending();
	test.displayList();
}*/

#endif // SEQUENCE_H