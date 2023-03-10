// TVector.h - Dynamic Array
#pragma once

#include <cassert>	// assert

template<typename T>
class TVector
{
	// pointer to the underlying array
	T * arr;
	// store the number of used elements
	size_t arrSize;
	// store the capacity of the underlying array
	size_t arrCapacity;

public:

	// TVector<T>::Iterator
	class Iterator
	{
		TVector * vec;
		size_t cur;

	public:
		Iterator();

		Iterator(TVector * target, size_t start);

		bool operator==(const Iterator & rhs) const;
		bool operator!=(const Iterator & rhs) const;

		Iterator operator+(size_t offset);

		// pre-increment
		// increments and then returns itself
		Iterator & operator++();

		// post-increment
		// increment and then returns a copy of its former self
		// (before it was incremented)
		Iterator operator++(int);

		T& operator*() const;
	};

	// constructor
	TVector();
	// destructor
	~TVector();
	// copy constructor
	TVector(const TVector & vec);
	// copy assignment
	TVector& operator=(const TVector & vec);

	// get a pointer to the raw array
	T * Data();
	const T * Data() const;

	// adds an element to the end
	void Push_Back(const T & value);
	// removes an element from the end
	void Pop_Back();

	// get the element at a particular index
	T & At(size_t index);
	const T & At(size_t index) const;

	T& Back();
	const T& Back () const;

	// how many elements are in this TVector?
	size_t Size() const;
	// how many elements can this TVector store?
	size_t Capacity() const;

	bool Empty() const;
	void Resize(size_t newSize);
	void Reserve(size_t newCapacity);
	void Shrink_To_Fit();
	void Clear();
	void Remove(const T & valToRemove);
	bool Contains(const T & searchValue);

	// subscript operator
	T& operator[] (size_t index);
	const T & operator[] (size_t index) const;

	Iterator begin();
	Iterator end();
};

template<typename T>
TVector<T>::TVector()
{
	arr = nullptr;
	arrSize = 0;
	arrCapacity = 0;
}

template<typename T>
TVector<T>::~TVector()
{
	delete[] arr;
	arr = nullptr;
	arrSize = 0;
	arrCapacity = 0;
}

template<typename T>
TVector<T>::TVector(const TVector & vec)
{
	arr = new T[vec.arrCapacity];
	arrCapacity = vec.arrCapacity;
	arrSize = vec.arrSize;

	// copy over the data
	for (size_t i = 0; i < arrSize; ++i)
	{
		arr[i] = vec.arr[i];
	}
}

template<typename T>
TVector<T>& TVector<T>::operator=(const TVector & vec)
{
	delete[] arr;

	arr = new T[vec.arrCapacity];
	arrCapacity = vec.arrCapacity;
	arrSize = vec.arrSize;

	// copy over the data
	for (size_t i = 0; i < arrSize; ++i)
	{
		arr[i] = vec.arr[i];
	}

	return *this;
}

template<typename T>
T* TVector<T>::Data()
{
	return arr;
}

template<typename T>
const T * TVector<T>::Data() const
{
	return arr;
}

template<typename T>
void TVector<T>::Push_Back(const T & value)
{
	// check to see if we need to allocate more memory
	if (arrSize >= arrCapacity)
	{
		// if so, create a new array...
		size_t newCap = (arrSize + 1) * 2;
		T * newArr = new T[newCap];

		// and copy the old one into it...
		for (size_t i = 0; i < arrSize; ++i)
		{
			newArr[i] = arr[i];
		}

		// then delete the original
		delete[] arr;

		arr = newArr;
		arrCapacity = newCap;
	}

	// push the element into the end
	arr[arrSize] = value;
	// increase arrSize by one to reflect the newly pushed element
	++arrSize;
}

template<typename T>
void TVector<T>::Pop_Back()
{
	// manually "destroy" the object
	arr[arrSize].~T();
	// reduce the number of things in the dyn array
	--arrSize;
}

template<typename T>
T & TVector<T>::Back()
{
	return At(Size() - 1);
}

template<typename T>
const T & TVector<T>::Back() const
{
	return At(Size() - 1);
}

template<typename T>
T & TVector<T>::At(size_t index)
{
	// check for out of bounds error
	// ...
	// we COULD also throw an exception, though they're rare in
	// game projects
	assert(index < arrSize && "Index for 'At' was out of bounds!");

	return arr[index];
}

template<typename T>
const T & TVector<T>::At(size_t index) const
{
	// check for out of bounds error
	// ...
	// we COULD also throw an exception, though they're rare in
	// game projects
	assert(index < arrSize && "Index for 'At' was out of bounds!");

	return arr[index];
}

template<typename T>
size_t TVector<T>::Size() const
{
	return arrSize;
}

template<typename T>
size_t TVector<T>::Capacity() const
{
	return arrCapacity;
}

template<typename T>
bool TVector<T>::Empty() const
{
	return arrSize == 0;
}

template<typename T>
void TVector<T>::Resize(size_t newSize)
{
	// if the vector gets larger, we add new elements
	// (size of 3 => 5)
	// pushes +2 new elements
	
	// if the vector gets smaller, we pop excessive elements
	// (size of 5 => 3)
	// pop -2 extra elements

	int change = newSize - arrSize;

	// grow
	if (change > 0)
	{
		for (size_t i = 0; i < change; ++i)
		{
			Push_Back(T());
		}
	}
	// shrink
	else if (change < 0)
	{
		for (size_t i = 0; i < -change; ++i)
		{
			Pop_Back();
		}
	}

	// 0 - we do nothing!
}

template<typename T>
void TVector<T>::Reserve(size_t newCapacity)
{
	// grow the array
	if (newCapacity > arrCapacity)
	{
		T * newArr = new T[newCapacity];

		for (size_t i = 0; i < arrSize; ++i)
		{
			newArr[i] = arr[i];
		}

		delete[] arr;
		arr = newArr;
		arrCapacity = newCapacity;
	}
}

template<typename T>
void TVector<T>::Shrink_To_Fit()
{
	T* newArr = new T[arrSize];

	for (size_t i = 0; i < arrSize; ++i)
	{
		newArr[i] = arr[i];
	}

	delete[] arr;
	arr = newArr;

	arrCapacity = arrSize;
}

template<typename T>
void TVector<T>::Clear()
{
	int numberToPop = Size();
	for (int i = 0; i < numberToPop; ++i)
	{
		Pop_Back();
	}
}

template<typename T>
void TVector<T>::Remove(const T & valToRemove)
{
	// search for the value
	for(size_t i = 0; i < arrSize; ++i)
	{
		if (arr[i] == valToRemove)
		{
			// shuffle everything down the line
			for (size_t j = 1; i + j < arrSize; ++i)
			{
				arr[i + j - 1] = arr[i + j];
			}
			// remove whatever's at the end
			Pop_Back();
		}
	}

	// TODO: test this!
}

template<typename T>
bool TVector<T>::Contains(const T & searchValue)
{
	for (auto & val : *this)
	{
		if (val == searchValue) { return true; }
	}

	// search exhausted, value not found
	return false;
}

template<typename T>
T & TVector<T>::operator[](size_t index)
{
	return At(index);
}

template<typename T>
const T & TVector<T>::operator[](size_t index) const
{
	return At(index);
}

template<typename T>
typename TVector<T>::Iterator TVector<T>::begin()
{
	return Iterator(this, 0);
}

template<typename T>
typename TVector<T>::Iterator TVector<T>::end()
{
	return Iterator(this, arrSize);
}

template<typename T>
TVector<T>::Iterator::Iterator()
{
	vec = nullptr;
	cur = 0;
}

template<typename T>
TVector<T>::Iterator::Iterator(TVector * target, size_t start)
{
	vec = target;
	cur = start;
}

template<typename T>
bool TVector<T>::Iterator::operator==(const Iterator & rhs) const
{
	return vec == rhs.vec && cur == rhs.cur;
}


template<typename T>
bool TVector<T>::Iterator::operator!=(const Iterator & rhs) const
{
	return !((*this) == rhs);
}

template<typename T>
typename TVector<T>::Iterator & TVector<T>::Iterator::operator++()
{
	++cur;
	return *this;
}

template<typename T>
typename TVector<T>::Iterator TVector<T>::Iterator::operator++(int)
{
	++cur;
	return Iterator(vec, cur - 1);
}

template<typename T>
T& TVector<T>::Iterator::operator*() const
{
	return (*vec)[cur];
}

template<typename T>
typename TVector<T>::Iterator TVector<T>::Iterator::operator+(size_t offset)
{
	return Iterator(vec, cur + offset);
}