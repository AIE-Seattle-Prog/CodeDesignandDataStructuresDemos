#include <list>

int main()
{
	std::list<int> numbers({ 1,2,3,4 });

	auto last = --numbers.end();

	int value = *last;

	return 0;
}