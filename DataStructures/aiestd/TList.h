#pragma once

template<typename T>
class TList
{
public:
	TList();
	~TList();

	void Push_Front(const T & value);

	T & Front();
};

template<typename T>
inline TList<T>::TList()
{
}

template<typename T>
inline TList<T>::~TList()
{
}

template<typename T>
inline void TList<T>::Push_Front(const T & value)
{
}

template<typename T>
inline T & TList<T>::Front()
{
	return T();
}
