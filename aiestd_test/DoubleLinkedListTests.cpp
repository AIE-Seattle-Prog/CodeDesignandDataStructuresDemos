#include "pch.h"
//#include "CppUnitTest.h"
//#include "tracker.h"
//
//#include "TList.h"
//
//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//
//namespace aiestd_test
//{
//	TEST_CLASS(listTests)
//	{
//		TEST_CLASS_INITIALIZE(Init)
//		{
//			tracker::Reset();
//		}
//
//		// Validates that Push_Front Pushes objects to the Front
//		//
//		// Also requires Front() for validating the value of the object
//		TEST_METHOD(Push_Front_and_Front)
//		{
//			TList<tracker> trackers;
//			int baseCount = tracker::count();
//
//			trackers.Push_Front(tracker(5));
//			Assert::AreEqual(baseCount + 1, tracker::count(), L"Did not allocate a new instance of T for storage");
//			Assert::AreEqual(trackers.Front(), tracker(5), L"Value at Front was not as expected");
//
//			trackers.Push_Front(tracker(7));
//			Assert::AreEqual(baseCount + 2, tracker::count(), L"Did not allocate a new instance of T for storage");
//			Assert::AreEqual(trackers.Front(), tracker(7), L"Value at Front was not as expected");
//		}
//
//		// Validates that objects Popped off the Front are destroyed
//		TEST_METHOD(Pop_Front_and_Front)
//		{
//			TList<tracker> trackers;
//			int baseCount = tracker::count();
//			trackers.Push_Front(tracker(5));
//			trackers.Pop_Front();
//			Assert::AreEqual(baseCount, tracker::count(), L"Value was not destroyed after being Popped");
//
//			trackers.Push_Front(tracker(7));
//			Assert::AreEqual(baseCount + 1, tracker::count(), L"Value was not added to the list - failed after Popping the last element prior");
//			Assert::AreEqual(trackers.Front(), tracker(7), L"Value at Front was not as expected");
//
//			trackers.Push_Front(tracker(9));
//			Assert::AreEqual(baseCount + 2, tracker::count(), L"Value was not added to the list");
//			Assert::AreEqual(trackers.Front(), tracker(9), L"Value at Front was not as expected");
//
//			trackers.Pop_Front();
//			Assert::AreEqual(trackers.Front(), tracker(7), L"Value at Front was not as expected");
//			Assert::AreEqual(baseCount + 1, tracker::count(), L"Value was not destroyed after being Popped");
//		}
//
//		// Validates that Push_Back Pushes objects to the Back
//		//
//		// Also requires Back() for validating the value of the object
//		TEST_METHOD(Push_Back_and_Back)
//		{
//			TList<tracker> trackers;
//			int baseCount = tracker::count();
//
//			trackers.Push_Back(tracker(5));
//			Assert::AreEqual(baseCount + 1, tracker::count(), L"Did not allocate a new instance of T for storage");
//			Assert::AreEqual(trackers.Back(), tracker(5), L"Value at Back was not as expected");
//
//			trackers.Push_Back(tracker(7));
//			Assert::AreEqual(baseCount + 2, tracker::count(), L"Did not allocate a new instance of T for storage");
//			Assert::AreEqual(trackers.Back(), tracker(7), L"Value at Back was not as expected");
//		}
//
//		// Validates that objects Popped off the Back are destroyed
//		TEST_METHOD(Pop_Back_and_Back)
//		{
//			TList<tracker> trackers;
//			int baseCount = tracker::count();
//			trackers.Push_Back(tracker(5));
//			trackers.Pop_Back();
//			Assert::AreEqual(baseCount, tracker::count(), L"Value was not destroyed after being Popped");
//
//			trackers.Push_Back(tracker(7));
//			Assert::AreEqual(baseCount + 1, tracker::count(), L"Value was not added to the list - failed after Popping the last element");
//			Assert::AreEqual(tracker(7), trackers.Back(), L"Value at Back was not as expected");
//
//			trackers.Push_Back(tracker(9));
//			Assert::AreEqual(baseCount + 2, tracker::count(), L"Value was not added to the list");
//			Assert::AreEqual(tracker(9), trackers.Back(), L"Value at Back was not as expected");
//
//			trackers.Pop_Back();
//			Assert::AreEqual(trackers.Back(), tracker(7), L"Value at Front was not as expected");
//			Assert::AreEqual(baseCount + 1, tracker::count(), L"Value was not destroyed after being Popped");
//		}
//
//		TEST_METHOD(PushPop_FrontBack)
//		{
//			TList<tracker> trackers;
//			int baseCount = tracker::count();
//
//			// Pushing and Popping from Back
//
//			trackers.Push_Back(tracker(5));
//			trackers.Pop_Back();
//			Assert::AreEqual(baseCount, tracker::count(), L"Value was not destroyed after being Popped");
//
//			trackers.Push_Back(tracker(7));
//			Assert::AreEqual(baseCount + 1, tracker::count(), L"Value was not added to the list - failed after Popping the last element");
//			Assert::AreEqual(trackers.Front(), tracker(7), L"Value at Front was not as expected");
//			Assert::AreEqual(trackers.Back(), tracker(7), L"Value at Back was not as expected");
//
//			trackers.Push_Back(tracker(9));
//			Assert::AreEqual(baseCount + 2, tracker::count(), L"Value was not added to the list");
//			Assert::AreEqual(trackers.Front(), tracker(7), L"Value at Front was not as expected");
//			Assert::AreEqual(trackers.Back(), tracker(9), L"Value at Back was not as expected");
//
//			trackers.Pop_Back();
//			Assert::AreEqual(trackers.Front(), tracker(7), L"Value at Front was not as expected");
//			Assert::AreEqual(trackers.Back(), tracker(7), L"Value at Back was not as expected");
//			Assert::AreEqual(baseCount + 1, tracker::count(), L"Value was not destroyed after being Popped");
//
//			// clearing the list
//
//			trackers.Pop_Back();
//			Assert::AreEqual(baseCount, tracker::count(), L"Value was not destroyed after being Popped");
//
//			// Pushing and Popping from Front
//
//			trackers.Push_Front(tracker(5));
//			trackers.Pop_Front();
//			Assert::AreEqual(baseCount, tracker::count(), L"Value was not destroyed after being Popped");
//
//			trackers.Push_Front(tracker(7));
//			Assert::AreEqual(baseCount + 1, tracker::count(), L"Value was not added to the list - failed after Popping the last element prior");
//			Assert::AreEqual(tracker(7), trackers.Front(), L"Value at Front was not as expected");
//			Assert::AreEqual(tracker(7), trackers.Back(), L"Value at Back was not as expected");
//
//			trackers.Push_Front(tracker(9));
//			Assert::AreEqual(baseCount + 2, tracker::count(), L"Value was not added to the list");
//			Assert::AreEqual(tracker(9), trackers.Front(), L"Value at Front was not as expected");
//			Assert::AreEqual(tracker(7), trackers.Back(), L"Value at Back was not as expected");
//
//			trackers.Pop_Front();
//			Assert::AreEqual(tracker(7), trackers.Front(), L"Value at Front was not as expected");
//			Assert::AreEqual(tracker(7), trackers.Back(), L"Value at Back was not as expected");
//			Assert::AreEqual(baseCount + 1, tracker::count(), L"Value was not destroyed after being Popped");
//		}
//
//		// copy constructor - part of rule of three
//		TEST_METHOD(copy_ctor)
//		{
//			TList<int> numbers;
//			numbers.Push_Back(1);
//			numbers.Push_Back(2);
//			numbers.Push_Back(3);
//
//			// invoke the copy constructor
//			// this is equivalent to TList<int> otherNumbers(numbers)
//			TList<int> otherNumbers = numbers;
//			Assert::AreEqual(numbers.Back(), 3, L"Value at Back was not as expected");
//			Assert::AreEqual(otherNumbers.Back(), 3, L"Value at Back was not as expected");
//
//			otherNumbers.Pop_Back();
//			Assert::AreEqual(numbers.Back(), 3, L"Value at Back was not as expected");
//			Assert::AreEqual(otherNumbers.Back(), 2, L"Value at Back was not as expected");
//
//			otherNumbers.Pop_Back();
//			Assert::AreEqual(numbers.Back(), 3, L"Value at Back was not as expected");
//			Assert::AreEqual(otherNumbers.Back(), 1, L"Value at Back was not as expected");
//		}
//
//		// copy assignment - part of rule of three
//		TEST_METHOD(copy_assign)
//		{
//			TList<int> numbers;
//			numbers.Push_Back(1);
//			numbers.Push_Back(2);
//			numbers.Push_Back(3);
//
//			// assigning to an existing but Empty list
//			TList<int> otherNumbers;
//			otherNumbers = numbers;
//			Assert::AreEqual(3, numbers.Back(), L"Value at Back was not as expected - original list should be unchanged");
//			Assert::AreEqual(3, otherNumbers.Back(), L"Value at Back was not as expected");
//
//			otherNumbers.Pop_Back();
//			Assert::AreEqual(3, numbers.Back(), L"Value at Back was not as expected - original list should be unchanged");
//			Assert::AreEqual(otherNumbers.Back(), 2, L"Value at Back was not as expected");
//
//			otherNumbers.Pop_Back();
//			Assert::AreEqual(3, numbers.Back(), L"Value at Back was not as expected - original list should be unchanged");
//			Assert::AreEqual(1, otherNumbers.Back(), L"Value at Back was not as expected");
//
//			// assigning to an existing and pre-Populated list
//			TList<int> existingNumbers;
//			existingNumbers.Push_Back(99);
//			existingNumbers.Push_Back(533);
//			existingNumbers.Push_Back(7444);
//			// ^^ junk data that won't persist after copy assignment
//
//			existingNumbers = numbers;
//			Assert::AreEqual(3, numbers.Back(), L"Value at Back was not as expected - original list should be unchanged");
//			Assert::AreEqual(3, existingNumbers.Back(), L"Value at Back was not as expected");
//
//			existingNumbers.Pop_Back();
//			Assert::AreEqual(3, numbers.Back(), L"Value at Back was not as expected - original list should be unchanged");
//			Assert::AreEqual(existingNumbers.Back(), 2, L"Value at Back was not as expected");
//
//			existingNumbers.Pop_Back();
//			Assert::AreEqual(3, numbers.Back(), L"Value at Back was not as expected - original list should be unchanged");
//			Assert::AreEqual(1, existingNumbers.Back(), L"Value at Back was not as expected");
//		}
//
//		// validating that Front() has an overload for const-qualified
//		TEST_METHOD(Front_const)
//		{
//			TList<int> numbers;
//			numbers.Push_Front(1);
//			numbers.Push_Back(2);
//			numbers.Push_Back(3);
//
//			const TList<int>& numbersConst = numbers;
//			Assert::AreEqual(1, numbers.Front(), L"Value at Front (const) was not as expected");
//		}
//
//		// validating that Back() has an overload for const-qualified
//		TEST_METHOD(Back_const)
//		{
//			TList<int> numbers;
//			numbers.Push_Front(1);
//			numbers.Push_Back(2);
//			numbers.Push_Back(3);
//
//			const TList<int>& numbersConst = numbers;
//			Assert::AreEqual(3, numbers.Back(), L"Value at Back (const) was not as expected");
//		}
//
//		TEST_METHOD(RemoveByValue)
//		{
//			// if we remove 2s from this list...
//			// 1 1 2 2 3 3
//			// then we should have...
//			// 1 1 3 3
//			TList<int> numbers;
//			numbers.Push_Front(1);
//			numbers.Push_Back(1);
//			numbers.Push_Back(2);
//			numbers.Push_Back(2);
//			numbers.Push_Back(3);
//			numbers.Push_Back(3);
//
//			numbers.Remove(2);
//
//			Assert::AreEqual(3, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//			Assert::AreEqual(3, numbers.Back(), L"Value at Back was not as expected");
//
//			numbers.Pop_Back();
//			Assert::AreEqual(1, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//			Assert::AreEqual(1, numbers.Back(), L"Value at Back was not as expected");
//		}
//
//		TEST_METHOD(RemoveByValue_Head)
//		{
//			// if we remove 1s from this list...
//			// 1 1 2 2 3 3
//			// then we should have...
//			// 2 2 3 3
//			TList<int> numbers;
//			numbers.Push_Front(1);
//			numbers.Push_Back(1);
//			numbers.Push_Back(2);
//			numbers.Push_Back(2);
//			numbers.Push_Back(3);
//			numbers.Push_Back(3);
//
//			numbers.Remove(1);
//
//			Assert::AreEqual(2, numbers.Front(), L"Value at Front as not as expected");
//			Assert::AreEqual(3, numbers.Back(), L"Value at Back as not as expected");
//
//			Assert::AreEqual(3, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//			Assert::AreEqual(3, numbers.Back(), L"Value at Back was not as expected");
//
//			numbers.Pop_Back();
//			Assert::AreEqual(2, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//			Assert::AreEqual(2, numbers.Back(), L"Value at Back was not as expected");
//
//		}
//
//		TEST_METHOD(RemoveByValue_Tail)
//		{
//			// if we remove 3s from this list...
//			// 1 1 2 2 3 3
//			// then we should have...
//			// 1 1 2 2
//			TList<int> numbers;
//			numbers.Push_Front(1);
//			numbers.Push_Back(1);
//			numbers.Push_Back(2);
//			numbers.Push_Back(2);
//			numbers.Push_Back(3);
//			numbers.Push_Back(3);
//
//			numbers.Remove(3);
//
//			Assert::AreEqual(1, numbers.Front(), L"Value at Front as not as expected");
//			Assert::AreEqual(2, numbers.Back(), L"Value at Back as not as expected");
//
//			Assert::AreEqual(2, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//			Assert::AreEqual(2, numbers.Back(), L"Value at Back was not as expected");
//
//			numbers.Pop_Back();
//			Assert::AreEqual(1, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//			Assert::AreEqual(1, numbers.Back(), L"Value at Back was not as expected");
//		}
//
//		TEST_METHOD(RemoveByIterator)
//		{
//			// if we remove the element [1] from this list...
//			// 1 1 2 2 3 3
//			// then we should have...
//			// 1 2 2 3 3
//			TList<int> numbers;
//			numbers.Push_Front(1);
//			numbers.Push_Back(1);
//			numbers.Push_Back(2);
//			numbers.Push_Back(2);
//			numbers.Push_Back(3);
//			numbers.Push_Back(3);
//
//			numbers.Remove(++numbers.begin());
//
//			Assert::AreEqual(3, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//			Assert::AreEqual(3, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//
//			Assert::AreEqual(2, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//			Assert::AreEqual(2, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//
//			Assert::AreEqual(1, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//
//			Assert::IsTrue(numbers.Empty());
//		}
//
//		TEST_METHOD(RemoveByIterator_Head)
//		{
//			// if we remove the head element from this list...
//			// 1 2 3 4 5 6
//			// then we should have...
//			// 2 3 4 5 6
//			TList<int> numbers;
//			numbers.Push_Front(1);
//			numbers.Push_Back(2);
//			numbers.Push_Back(3);
//			numbers.Push_Back(4);
//			numbers.Push_Back(5);
//			numbers.Push_Back(6);
//
//			numbers.Remove(numbers.begin());
//
//			Assert::AreEqual(6, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//			Assert::AreEqual(5, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//
//			Assert::AreEqual(4, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//			Assert::AreEqual(3, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//
//			Assert::AreEqual(2, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//		}
//
//		TEST_METHOD(RemoveByIterator_Tail)
//		{
//			// if we remove the tail element from this list...
//			// 1 2 3 4 5 6
//			// then we should have...
//			// 1 2 3 4 5
//			TList<int> numbers;
//			numbers.Push_Front(1);
//			numbers.Push_Back(2);
//			numbers.Push_Back(3);
//			numbers.Push_Back(4);
//			numbers.Push_Back(5);
//			numbers.Push_Back(6);
//
//			numbers.Remove(--numbers.end());
//
//			Assert::AreEqual(5, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//
//			Assert::AreEqual(4, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//			Assert::AreEqual(3, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//
//			Assert::AreEqual(2, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//			Assert::AreEqual(1, numbers.Back(), L"Value at Back was not as expected");
//			numbers.Pop_Back();
//		}
//
//		TEST_METHOD(Empty)
//		{
//			// default list should be Empty
//			TList<int> nothing;
//			TList<int>& nothingRef = nothing;
//			Assert::IsTrue(nothingRef.Empty(), L"List was not Empty");
//
//			// list should be Empty when you Push Back and Pop Back
//			TList<int> clearedBack;
//			clearedBack.Push_Back(5);
//			clearedBack.Pop_Back();
//			TList<int>& clearedRefB = clearedBack;
//			Assert::IsTrue(clearedRefB.Empty(), L"List was not Empty");
//
//			// list should be Empty when you Push Front and Pop Front
//			TList<int> clearedFront;
//			clearedFront.Push_Front(5);
//			clearedFront.Pop_Front();
//			TList<int>& clearedRefF = clearedFront;
//			Assert::IsTrue(clearedRefF.Empty(), L"List was not Empty");
//		}
//
//		TEST_METHOD(clear)
//		{
//			// list should be clear after you Push thrice and clear
//			TList<tracker> trackers;
//			int baseCount = tracker::count();
//			trackers.Push_Front(tracker(5));
//			trackers.Push_Front(tracker(7));
//			trackers.Push_Front(tracker(9));
//
//			trackers.Clear();
//			Assert::IsTrue(trackers.Empty(), L"List was not Empty");
//			Assert::AreEqual(baseCount, tracker::count(), L"Number of outstanding allocations was not as expected");
//
//			// make sure the list behaves as expected after clearing
//
//			trackers.Push_Back(7);
//			Assert::AreEqual(tracker(7), trackers.Front(), L"Value from Front was not as expected");
//			Assert::AreEqual(tracker(7), trackers.Back(), L"Value from Back was not as expected");
//
//			trackers.Push_Front(5);
//			Assert::AreEqual(tracker(5), trackers.Front(), L"Value from Front was not as expected");
//			Assert::AreEqual(tracker(7), trackers.Back(), L"Value from Back was not as expected");
//		}
//
//		TEST_METHOD(resize)
//		{
//			TList<tracker> fromEmpty;
//			fromEmpty.Resize(5);
//
//			// NOTE: forgot to ask students to implement a `Size` function
//			// so this is our next best option - Pop until Empty
//			size_t listSize = 0;
//			while (!fromEmpty.Empty())
//			{
//				++listSize;
//				fromEmpty.Pop_Back();
//			}
//			Assert::AreEqual((size_t)5, listSize, L"List did not contain the expected number of elements");
//
//			TList<tracker> sizeUp;
//			sizeUp.Push_Front(1);
//			sizeUp.Push_Front(1);
//			sizeUp.Resize(4);
//
//			Assert::AreEqual(tracker(), sizeUp.Back(), L"Extra elements from resizing up don't seem to be default initialized");
//
//			// NOTE: forgot to ask students to implement a `Size` function
//			// so this is our next best option - Pop until Empty
//			listSize = 0;
//			while (!sizeUp.Empty())
//			{
//				++listSize;
//				sizeUp.Pop_Back();
//			}
//			Assert::AreEqual((size_t)4, listSize, L"List did not contain the expected number of elements");
//
//			TList<tracker> sizeDown;
//			sizeDown.Push_Front(-1);
//			sizeDown.Push_Front(-1);
//			sizeDown.Push_Front(-1);
//			sizeDown.Push_Front(-1);
//
//			sizeDown.Resize(2);
//
//
//			// NOTE: forgot to ask students to implement a `Size` function
//			// so this is our next best option - Pop until Empty
//			listSize = 0;
//			while (!sizeDown.Empty())
//			{
//				++listSize;
//				sizeDown.Pop_Back();
//			}
//			Assert::AreEqual((size_t)2, listSize, L"List did not contain the expected number of elements");
//		}
//
//		TEST_METHOD(iterator_begin_and_deref)
//		{
//			TList<int> numbers;
//			numbers.Push_Front(5);
//			numbers.Push_Back(9);
//
//			auto it = numbers.begin();
//			Assert::AreEqual(5, *it, L"Iterator did not return the expected value at the Front");
//		}
//
//		TEST_METHOD(iterator_preinc)
//		{
//			TList<int> numbers;
//			numbers.Push_Front(5);
//			numbers.Push_Back(9);
//
//			auto it = numbers.begin();
//			Assert::AreEqual(9, *(++it), L"Iterator did not return the expected value");
//		}
//
//		TEST_METHOD(iterator_postinc)
//		{
//			TList<int> numbers;
//			numbers.Push_Front(5);
//			numbers.Push_Back(9);
//
//			auto it = numbers.begin();
//			Assert::AreEqual(5, *(it++), L"Iterator did not return the expected value");
//			Assert::AreEqual(9, *(it), L"Iterator did not return the expected value");
//		}
//
//		TEST_METHOD(iterator_predec)
//		{
//			TList<int> numbers;
//			numbers.Push_Front(5);
//			numbers.Push_Back(9);
//
//			auto it = numbers.begin();
//			++it;
//			Assert::AreEqual(5, *(--it), L"Iterator did not return the expected value");
//		}
//
//		TEST_METHOD(iterator_postdec)
//		{
//			TList<int> numbers;
//			numbers.Push_Front(5);
//			numbers.Push_Back(9);
//
//			auto it = numbers.begin();
//			++it;
//			Assert::AreEqual(9, *(it--), L"Iterator did not return the expected value");
//			Assert::AreEqual(5, *(it), L"Iterator did not return the expected value");
//		}
//
//		TEST_METHOD(iterator_end)
//		{
//			TList<int> numbers;
//			numbers.Push_Front(4);
//			numbers.Push_Back(9);
//
//			auto it = numbers.begin();
//			++it;
//			++it;
//			Assert::IsTrue(it == numbers.end(), L"Iterator did not return the expected value at the end");
//			//Assert::AreEqual(9, *(--it), L"Iterator did not return the expected value at the end");
//		}
//
//		TEST_METHOD(iterator_eq)
//		{
//			TList<int> numbers;
//			numbers.Push_Front(5);
//			numbers.Push_Back(9);
//
//			auto itA = numbers.begin();
//			Assert::IsTrue(itA == itA, L"Iterator was not considered equal to a copy of itself");
//
//			auto itB = numbers.begin();
//			Assert::IsTrue(itA == itB, L"Iterator was not considered equal to its equivalent");
//		}
//
//		TEST_METHOD(iterator_ineq)
//		{
//			TList<int> numbers;
//			numbers.Push_Front(5);
//			numbers.Push_Back(9);
//
//			auto itbeginA = numbers.begin();
//			Assert::IsFalse(itbeginA != itbeginA, L"Iterator was not considered inequal to a copy of itself");
//
//			auto itbeginB = numbers.begin();
//			Assert::IsFalse(itbeginA != itbeginB, L"Iterator was not considered inequal to its equivalent");
//
//			auto itend = numbers.end();
//			Assert::IsTrue(itbeginA != itend, L"Iterator was not considered inequal despite being different");
//		}
//
//		TEST_METHOD(iteration)
//		{
//			int numbers[] = { 1,3,5,7 };
//
//			TList<int> listNumbers;
//			listNumbers.Push_Back(1);
//			listNumbers.Push_Back(3);
//			listNumbers.Push_Back(5);
//			listNumbers.Push_Back(7);
//
//			size_t runs = 0;
//			auto it = listNumbers.begin();
//			for (auto& num : numbers)
//			{
//				Assert::AreEqual(num, *it);
//				++it;
//				++runs;
//			}
//
//			Assert::AreEqual((size_t)4, runs, L"Iteration took more/less runs than expected");
//		}
//
//		//TEST_METHOD(insert)
//		//{
//		//	int numbers[] = { 1,3,5,7 };
//
//		//	TList<int> listNumbers;
//		//	listNumbers.Push_Back(1);
//		//	listNumbers.Push_Back(3);
//		//	listNumbers.Push_Back(7);
//
//		//	auto insertionIt = listNumbers.end();
//		//	--insertionIt;
//
//		//	listNumbers.insert(insertionIt, 5);
//
//		//	auto it = listNumbers.begin();
//		//	for (auto &num : numbers)
//		//	{
//		//		Assert::AreEqual(num, *it);
//		//		++it;
//		//	}
//		//}
//
//		// -- EXTRAS --
//		//TEST_METHOD(iterator_cast_to_const_it)
//		//{
//		//	TList<int> listNumbers;
//		//	listNumbers.Push_Front(4);
//
//		//	auto it = listNumbers.begin();
//		//	auto cIt = TList<int>::const_iterator(it);
//
//		//	Assert::IsTrue(it == cIt, L"Iterators were not equal as expected");
//		//}
//	};
//}
