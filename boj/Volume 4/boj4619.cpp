#include <bits/stdc++.h>

using namespace std;

int pow(int x, int y) {
	int ret = 1;
	while (y--) {
		ret *= x;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int B{}, N{};
	while (cin >> B >> N, B) {
		if (N == 1) {
			cout << B << "\n";
			continue;
		}
		int x = 1;
		while (abs(B - pow(x, N)) > abs(B - pow(x + 1, N))) {
			++x;
		}
		cout << x << "\n";
	}
	return 0;
}
