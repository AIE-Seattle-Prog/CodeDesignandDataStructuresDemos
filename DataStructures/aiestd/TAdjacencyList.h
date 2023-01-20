#pragma once

#include "TVector.h"
#include "TList.h"
#include "TQueue.h"
#include "TStack.h"

#include <unordered_set>
#include <iostream>

template<typename T>
class TAdjacencyList
{
public:
	class Vertex
	{
		TVector<Vertex *> connections;

	public:
		T data;

		Vertex();
		Vertex(const T & val);

		void AddConnection(Vertex & other);
		void RemoveConnection(Vertex & other);

		bool IsConnected(const Vertex & other);
		Vertex * GetConnection(size_t index) const;

		size_t ConnectionCount() const;

		void PrintBFS();
		void PrintDFS();
		
		Vertex * SearchBFS(const T& searchValue);
		Vertex * SearchDFS(const T & searchValue);
	};

	Vertex & Add(const T & value);
	void Remove(Vertex & nodeToRemove);
private:
	TList<Vertex> vertices;
};

template<typename T>
TAdjacencyList<T>::Vertex::Vertex()
{
	data = T();
}

template<typename T>
TAdjacencyList<T>::Vertex::Vertex(const T & val)
{
	data = val;
}

template<typename T>
void TAdjacencyList<T>::Vertex::AddConnection(Vertex & other)
{
	connections.Push_Back(&other);
}

template<typename T>
void TAdjacencyList<T>::Vertex::RemoveConnection(Vertex & other)
{
	connections.Remove(&other);
}

template<typename T>
bool TAdjacencyList<T>::Vertex::IsConnected(const Vertex & other)
{
	return connections.Contains(&other);
}

template<typename T>
typename TAdjacencyList<T>::Vertex * TAdjacencyList<T>::Vertex::GetConnection(size_t index) const
{
	return connections[index];
}

template<typename T>
size_t TAdjacencyList<T>::Vertex::ConnectionCount() const
{
	return connections.Size();
}

template<typename T>
void TAdjacencyList<T>::Vertex::PrintBFS()
{
	TQueue<const Vertex *> todo;
	std::unordered_set<const Vertex *> seen;
	todo.Push(this);

	while (!todo.Empty())
	{
		const Vertex * current = todo.Front();
		todo.Pop();

		// "process" it
		std::cout << current->data << std::endl;
		seen.insert(current);

		// queue neighbors if not visited
		for (size_t i = 0; i < current->ConnectionCount(); ++i)
		{
			Vertex * potentialNeighbor = current->GetConnection(i);
			// if not seen
			if (seen.find(potentialNeighbor) == seen.end())
			{
				todo.Push(potentialNeighbor);
			}
		}
	}
}

template<typename T>
void TAdjacencyList<T>::Vertex::PrintDFS()
{
	TStack<const Vertex *> todo;
	std::unordered_set<const Vertex *> seen;
	todo.Push(this);

	while (!todo.Empty())
	{
		const Vertex * current = todo.Top();
		todo.Pop();

		// "process" it
		std::cout << current->data << std::endl;
		seen.insert(current);

		// queue neighbors if not visited
		for (size_t i = 0; i < current->ConnectionCount(); ++i)
		{
			Vertex * potentialNeighbor = current->GetConnection(current->ConnectionCount() - 1 - i);
			// if not seen
			if (seen.find(potentialNeighbor) == seen.end())
			{
				todo.Push(potentialNeighbor);
			}
		}
	}
}

template<typename T>
typename TAdjacencyList<T>::Vertex * TAdjacencyList<T>::Vertex::SearchBFS(const T& searchVal)
{
	TQueue<Vertex *> todo;
	std::unordered_set<Vertex *> seen;
	todo.Push(this);

	while (!todo.Empty())
	{
		Vertex * current = todo.Front();
		todo.Pop();

		// "process" it
		if (current->data == searchVal)
		{
			return current;
		}
		seen.insert(current);

		// queue neighbors if not visited
		for (size_t i = 0; i < current->ConnectionCount(); ++i)
		{
			Vertex * potentialNeighbor = current->GetConnection(i);
			// if not seen
			if (seen.find(potentialNeighbor) == seen.end())
			{
				todo.Push(potentialNeighbor);
			}
		}
	}

	return nullptr;
}

template<typename T>
typename TAdjacencyList<T>::Vertex * TAdjacencyList<T>::Vertex::SearchDFS(const T & searchVal)
{
	TStack<Vertex *> todo;
	std::unordered_set<Vertex *> seen;
	todo.Push(this);

	while (!todo.Empty())
	{
		Vertex * current = todo.Top();
		todo.Pop();

		// "process" it
		std::cout << current->data << std::endl;
		if (current->data == searchVal)
		{
			return current;
		}
		seen.insert(current);

		// queue neighbors if not visited
		for (size_t i = 0; i < current->ConnectionCount(); ++i)
		{
			Vertex * potentialNeighbor = current->GetConnection(current->ConnectionCount() - 1 - i);
			// if not seen
			if (seen.find(potentialNeighbor) == seen.end())
			{
				todo.Push(potentialNeighbor);
			}
		}
	}

	return nullptr;
}

template<typename T>
typename TAdjacencyList<T>::Vertex & TAdjacencyList<T>::Add(const T & value)
{
	vertices.Push_Back(Vertex(value));
	return vertices.Back();
}


template<typename T>
void TAdjacencyList<T>::Remove(Vertex & vertToRemove )
{
	for (auto & vert : vertices)
	{
		for (size_t i = 0; i < vert.ConnectionCount(); ++i)
		{
			vert.RemoveConnection(vertToRemove);
		}
	}

	for (auto it = vertices.begin(); it != vertices.end(); ++it)
	{
		if (&(*it) == &vertToRemove)
		{
			vertices.Remove(it);
		}
	}
}
