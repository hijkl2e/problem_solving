#include "vectorfunctions.h"

void backwards(std::vector<int> &vec) {
	for (int i = 0, j = vec.size() - 1; i < j; ++i, --j) {
		swap(vec[i], vec[j]);
	}
}

std::vector<int> everyOther(const std::vector<int> &vec) {
	std::vector<int> ret;
	for (int i = 0; i < vec.size(); i += 2) {
		ret.push_back(vec[i]);
	}
	return ret;
}

int smallest(const std::vector<int> &vec) {
	int ret = 1e9;
	for (int x : vec) {
		ret = std::min(ret, x);
	}
	return ret;
}

int sum(const std::vector<int> &vec) {
	int ret{};
	for (int x : vec) {
		ret += x;
	}
	return ret;
}

int veryOdd(const std::vector<int> &suchVector) {
	int ret{};
	for (int i = 1; i < suchVector.size(); i += 2) {
		if (suchVector[i] % 2) {
			++ret;
		}
	}
	return ret;
}
