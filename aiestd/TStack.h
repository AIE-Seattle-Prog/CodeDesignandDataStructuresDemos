#pragma once

#include "TVector.h"

template <typename T>
class TStack
{
	TVector<T> vec;

public:
	void Push(const T & value);
	void Pop();

	T & Top();
	const T & Top() const;

	size_t Size() const;

	size_t Empty() const;
};

template<typename T>
inline void TStack<T>::Push(const T & value)
{
	vec.Push_Back(value);
}

template<typename T>
inline void TStack<T>::Pop()
{
	vec.Pop_Back();
}

template<typename T>
inline T & TStack<T>::Top()
{
	return vec[vec.Size() - 1];
}

template<typename T>
inline const T & TStack<T>::Top() const
{
	return vec[vec.Size() - 1];
}

template<typename T>
inline size_t TStack<T>::Size() const
{
	return vec.Size();
}

template<typename T>
inline size_t TStack<T>::Empty() const
{
	return vec.Empty();
}
