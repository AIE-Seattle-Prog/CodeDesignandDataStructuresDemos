#pragma once

#include "TVector.h"

template <typename T>
class TQueue
{
	TVector<T> data;

public:
	void Push(const T & value);
	void Pop();

	T & Front();

	bool Empty() const;
};

template<typename T>
inline void TQueue<T>::Push(const T & value)
{
	data.Push_Back(value);
}

template<typename T>
inline void TQueue<T>::Pop()
{
	// move all elements to the left by one
	for (size_t i = 1; i < data.Size(); ++i)
	{
		data[i - 1] = data[i];
	}

	// pop the last element
	data.Pop_Back();
}

template<typename T>
inline T & TQueue<T>::Front()
{
	return data[0];
}

template<typename T>
inline bool TQueue<T>::Empty() const
{
	return data.Empty();
}
