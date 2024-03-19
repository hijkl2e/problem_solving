#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> K;
	int lo{}, hi{};
	lo = hi = -1;
	for (int i = 0; i < 20; ++i) {
		if (K & (1 << i)) {
			lo = lo == -1 ? i : lo;
			hi = i;
		}
	}
	if (lo == hi) {
		cout << K << " 0\n";
	} else {
		cout << (1 << (hi + 1)) << " " << (hi - lo + 1) << "\n";
	}
	return 0;
}
