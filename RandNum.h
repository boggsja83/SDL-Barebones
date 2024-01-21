#pragma once

#include <random>

class RandomNum
{
private:
public:

	RandomNum() {}
	RandomNum(RandomNum const& _rn) {}
	~RandomNum() {}

	//inclusive of _lo and _hi
	int random_int(int _lo, int _hi) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> distribution(_lo, _hi);
		return distribution(gen);
	}

};

