#include <iostream>
#include <forward_list> // singly-linked list

int main()
{
	std::forward_list<int> flexibleNumbers;

	flexibleNumbers.push_front(2);
	flexibleNumbers.push_front(4);
	flexibleNumbers.push_front(6);
	flexibleNumbers.push_front(8);
	flexibleNumbers.push_front(10);

	// T()

	flexibleNumbers.resize(7);

	for (auto & num : flexibleNumbers)
	{
		std::cout << num << std::endl;
	}

}