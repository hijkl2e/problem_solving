#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{}, P{};
	cin >> L >> P;
	for (int i = 0; i < 5; ++i) {
		int x{};
		cin >> x;
		cout << x - L * P << (i == 4 ? "\n" : " ");
	}
	return 0;
}
