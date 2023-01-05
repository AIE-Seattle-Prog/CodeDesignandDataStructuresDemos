#include <iostream>
#include "TVector.h"

#include <vector>

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

	return 0;
}