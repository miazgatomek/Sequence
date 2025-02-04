#include "Sequence.h"

int main()
{
	std::cout << "TESTING:";

	addDeleteNodesTest();
	addFixedIndexTest();
	deleteFixedPositionTest();
	displayListTest();
	displayGivenNodeTest();
	equalOperatorTest();
	increaseOperatorTest();
	constructorsTest();
	listSizeTest();
	shuffleFunctionTest();
	containsKeyTest();
	checkKeyInfoTest();
	swapNodesTest();
	swapDataTest();
	//sortTest();

	std::cout << "\n\nALL TESTS COMPLETED\n";
}
