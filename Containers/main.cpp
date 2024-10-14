#include <iostream>
#include <vector>

#include "Vector.hpp"


int main(int argc, char * argv[]) {
	JPContainer::Vector<int> v;
	std::vector<int> stdv;

	std::cout << "My vector performance" << std::endl;
	PerformanceClock clock;
	for (int i = 0; i < 100000000; i++)
		v.push(i);
	clock.endClock();


	std::cout << "Std vector performance" << std::endl;
	PerformanceClock c;
	for (int i = 0; i < 100000000; i++)
		stdv.push_back(i);
	c.endClock();


	return 0;
}