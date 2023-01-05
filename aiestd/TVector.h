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

	// adds an element to the end
	void Push_Back(const T & value);
	// removes an element from the end
	void Pop_Back();

	// get the element at a particular index
	T & At(size_t index);

	// how many elements are in this TVector?
	size_t Size() const;
	// how many elements can this TVector store?
	size_t Capacity() const;

	bool Empty() const;
	void Resize(size_t newSize);
	void Reserve(size_t newCapacity);
	void Shrink_To_Fit();
	void Clear();

	// subscript operator
	T& operator[] (size_t index);
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
T & TVector<T>::operator[](size_t index)
{
	return At(index);
}