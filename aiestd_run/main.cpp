#include <iostream>
#include <vector>

#include <algorithm>

#include <stack>
#include <queue>

#include "TVector.h"
#include "TStack.h"

// POINTER vs REFERENCE?!
//
// pointer => a memory address 0x12378129
//			  can be be reassigned - point to a new object
//            can be null
//
// reference => an alias (refers to something)
//			    can be initialized once, and only once
//              must refer to something (though that something might not be valid...)

void PrintVecOfNumbers(const TVector<int> &numbers );

int main()
{
	TVector<int> numbers;

	numbers.Push_Back(5);
	numbers.Push_Back(10);

	std::cout << "Printing using 'at' ..." << std::endl;
	for (int i = 0; i < numbers.Size(); ++i)
	{
		std::cout << numbers.At(i) << std::endl;
	}

	std::cout << "Printing using '[ ]' ..." << std::endl;
	for (int i = 0; i < numbers.Size(); ++i)
	{
		std::cout << numbers[i] << std::endl;
	}

	std::cout << "Popping ..." << std::endl;
	numbers.Pop_Back();
	std::cout << "Printing ..." << std::endl;
	for (int i = 0; i < numbers.Size(); ++i)
	{
		std::cout << numbers.At(i) << std::endl;
	}

	// copy constructor
	TVector<int> copyVec(numbers);

	// copy assignment
	TVector<int> copyAssignVec;
	copyAssignVec.Push_Back(7);
	copyAssignVec = numbers;

	// empty
	TVector<int> emptyVec;
	bool isEmpty = emptyVec.Empty();
	TVector<int> notEmptyVec(numbers);
	bool isntEmpty = notEmptyVec.Empty();

	// shrink to fit
	TVector<int> wastedSpace;
	wastedSpace.Push_Back(2);	// 2
	wastedSpace.Push_Back(4);
	wastedSpace.Push_Back(6);   // 4
	wastedSpace.Push_Back(8);
	wastedSpace.Push_Back(10);  // 8
	wastedSpace.Push_Back(12);
	wastedSpace.Push_Back(14);
	wastedSpace.Push_Back(16);
	wastedSpace.Push_Back(18);  // 16
	wastedSpace.Push_Back(20);
	wastedSpace.Push_Back(22);
	wastedSpace.Push_Back(24);

	wastedSpace.Shrink_To_Fit();

	// clear
	TVector<int> forDisposal;
	forDisposal.Push_Back(4);
	forDisposal.Push_Back(6);
	forDisposal.Push_Back(8);

	forDisposal.Clear();

	bool isCleared = forDisposal.Empty();

	// resize
	TVector<int> forResize;
	forResize.Push_Back(4);
	forResize.Push_Back(8);

	forResize.Resize(4);
	size_t growSize = forResize.Size();
	forResize.Resize(1);
	size_t shrinkSize = forResize.Size();

	// reserve
	TVector<int> reservingSpace;

	reservingSpace.Reserve(16);

	reservingSpace.Push_Back(2);
	reservingSpace.Push_Back(4);
	reservingSpace.Push_Back(6);
	reservingSpace.Push_Back(8);
	reservingSpace.Push_Back(10);

	reservingSpace.Push_Back(12);
	reservingSpace.Push_Back(14);
	reservingSpace.Push_Back(16);
	reservingSpace.Push_Back(18);
	reservingSpace.Push_Back(20);

	reservingSpace.Push_Back(22);
	reservingSpace.Push_Back(24);

	std::vector<int> numbs;
	numbs.push_back(3);
	numbs.push_back(6);
	numbs.push_back(9);

	// index based for
	for (size_t i = 0; i < numbs.size(); ++i)
	{
		std::cout << numbs[i] << std::endl;
	}

	// iterator based for
	for (auto it = numbs.begin(); it != numbs.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	// range based for
	for (int & num : numbs)
	{
		std::cout << num << std::endl;
	}

	TVector<int> vecIter;	// int is 4 bytes
	vecIter.Push_Back(4);	// 0
	vecIter.Push_Back(6);   // 4
	vecIter.Push_Back(10);  // 8

	std::cout << "ITERATOR-based loop" << std::endl;
	for (auto it = vecIter.begin(); it != vecIter.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "RANGE-based loop" << std::endl;
	for (auto & num : vecIter)
	{
		std::cout << num << std::endl;
	}

	auto secondIt = vecIter.begin() + 1;
	int secondVal = *secondIt;

	std::vector<int> numbersss;
	numbersss.push_back(3);
	numbersss.push_back(6);
	numbersss.push_back(9);

	std::cout << "AFTER REMOVE loop" << std::endl;

	std::remove(numbersss.begin(), numbersss.end(), 6);
	numbersss.pop_back();
	for (auto & num : numbersss)
	{
		std::cout << num << std::endl;
	}

	std::cout << "========STACK========" << std::endl;

	std::stack<char> stlStack;
	TStack<char> myStack;

	stlStack.push('T');
	stlStack.push('e');
	stlStack.push('r');
	stlStack.push('r');
	stlStack.push('y');

	myStack.Push('T');
	myStack.Push('e');
	myStack.Push('r');
	myStack.Push('r');
	myStack.Push('y');

	TStack<char> copyOfMyStack = myStack;

	std::cout << "~STL stack~" << std::endl;
	while (!stlStack.empty())
	{
		std::cout << stlStack.top() << std::endl;
		stlStack.pop();
	}

	std::cout << "~my stack~" << std::endl;
	while (!myStack.Empty())
	{
		std::cout << myStack.Top() << std::endl;
		myStack.Pop();
	}

	std::cout << "~copy of my stack~" << std::endl;
	while (!copyOfMyStack.Empty())
	{
		std::cout << copyOfMyStack.Top() << std::endl;
		copyOfMyStack.Pop();
	}


	return 0;
}
