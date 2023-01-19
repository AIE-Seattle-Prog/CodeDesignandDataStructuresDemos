#pragma once

#include <string>

#include "CppUnitTest.h"

class tracker
{
	static int _count;

public:
	int data;

	tracker()
	{
		++_count;
		data = 0;
	}

	tracker(int newData)
	{
		++_count;
		data = newData;
	}

	tracker(const tracker &other)
	{
		++_count;
		data = other.data;
	}

	~tracker()
	{
		--_count;
	}

	bool operator==(const tracker &other) const
	{
		return data == other.data;
	}

	bool operator!=(const tracker &other) const
	{
		return *this != other;
	}

	bool operator<(const tracker &other) const
	{
		return data < other.data;
	}

	bool operator>(const tracker &other) const
	{
		return data > other.data;
	}

	bool operator<=(const tracker &other) const
	{
		return data <= other.data;
	}

	bool operator>=(const tracker &other) const
	{
		return data >= other.data;
	}

	void static Reset()
	{
		_count = 0;
	}

	int static count()
	{
		return _count;
	}

	bool static isZero()
	{
		return _count == 0;
	}
};

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> inline std::wstring ToString<tracker>(const tracker &t) { return std::to_wstring(t.data); }
		}
	}
}
