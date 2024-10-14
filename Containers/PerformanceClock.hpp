#pragma once

#include <chrono>
#include <iostream>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;


class PerformanceClock {
private:
	high_resolution_clock _startClock;
	high_resolution_clock _endClock;
	std::chrono::steady_clock::time_point t1;
	std::chrono::steady_clock::time_point t2;
	duration<double, std::milli> ms_double;
	bool end;

public:
	PerformanceClock() {
		startClock();
		end = true;
	}

	~PerformanceClock() {
		if(end) endClock();

		print();
	}

	void startClock() {
		t1 = _startClock.now();
		end = true;
	}

	void endClock() {
		t2 = _endClock.now();
		ms_double = t2 - t1;
		end = false;
	}

	void print() const {
		if (end == false)
			std::cout << "Performance clock: " << ms_double.count() << "ms\n";
		else
			std::cout << "Performance clock: please stop clock! " << std::endl;
	}
};