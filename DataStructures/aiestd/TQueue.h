#pragma once

#include "TVector.h"

template <typename T>
class TQueue
{
	// position of the front-most value
	size_t frontIndex;
	// position of the back-most value
	size_t backIndex;

	T* data;
	size_t dataCapacity;

public:
	TQueue();
	~TQueue();
	// copy ctor
	// copy assign

	void Push(const T & value);
	void Pop();

	T & Front();

	bool Empty() const;
};

template<typename T>
TQueue<T>::TQueue<T>()
{
	frontIndex = 0;
	backIndex = 0;

	data = new T[1];
	dataCapacity = 1;
}

template<typename T>
TQueue<T>::~TQueue<T>()
{
	delete[] data;
	dataCapacity = 0;

	frontIndex = 0;
	backIndex = 0;
}

template<typename T>
inline void TQueue<T>::Push(const T & value)
{
	// detect if a reallocation is necessary
	if ((backIndex + 1) % dataCapacity == frontIndex)
	{
		size_t size = (backIndex - frontIndex + dataCapacity) % dataCapacity;
		
		size_t newCapacity = (dataCapacity + 1) * 2;
		T * newData = new T[newCapacity];
		
		// copy over existing data (if any)
		for (size_t i = 0; i < size; ++i)
		{
			newData[i] = data[(frontIndex + i) % dataCapacity];
		}

		delete[] data;
		data = newData;
		dataCapacity = newCapacity;

		frontIndex = 0;
		backIndex = size;
	}

	data[backIndex] = value;
	backIndex = (backIndex + 1) % dataCapacity;
}

template<typename T>
inline void TQueue<T>::Pop()
{
	// TODO: add some error checking

	// destroy data at front index
	data[frontIndex].~T();
	frontIndex = (frontIndex + 1) % dataCapacity;
}

template<typename T>
inline T & TQueue<T>::Front()
{
	return data[frontIndex];
}

template<typename T>
inline bool TQueue<T>::Empty() const
{
	return frontIndex == backIndex;
}
