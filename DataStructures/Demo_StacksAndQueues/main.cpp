#include <iostream>

#include <vector>
#include <stack>
#include <queue>

using std::vector;
using std::stack;
using std::queue;

int main()
{
	vector<int> numbers;
	numbers.push_back(4);
	numbers.push_back(6);
	numbers.push_back(8);
	numbers.push_back(10);

	std::cout << "--VECTOR--" << std::endl;
	for (int &num : numbers)
	{
		std::cout << num << std::endl;
	}

	stack<int> pancakes;
	pancakes.push(4);
	pancakes.push(6);
	pancakes.push(8);
	pancakes.push(10);

	std::cout << "--STACK--" << std::endl;
	while (!pancakes.empty())
	{
		std::cout << pancakes.top() << std::endl;
		pancakes.pop();
	}

	queue<int> checkoutCounter;
	checkoutCounter.push(4);
	checkoutCounter.push(6);
	checkoutCounter.push(8);
	checkoutCounter.push(10);

	std::cout << "--QUEUE--" << std::endl;
	while (!checkoutCounter.empty())
	{
		std::cout << checkoutCounter.front() << std::endl;
		checkoutCounter.pop();
	}
}