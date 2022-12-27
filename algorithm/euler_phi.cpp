#include <bits/stdc++.h>

using namespace std;

int phi(int x) {
	int ret = 1;
	for (int i = 2; i * i <= x; ++i) {
		int y = 1;
		while (x % i == 0) {
			x /= i;
			y *= i;
		}
		ret *= y - y / i;
	}
	if (x > 1) {
		ret *= x - 1;
	}
	return ret;
}
