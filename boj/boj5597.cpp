#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	deque<bool> A(31);
	for (int i = 0; i < 28; ++i) {
		int x{};
		cin >> x;
		A[x] = true;
	}
	for (int i = 1; i < 31; ++i) {
		if (!A[i]) {
			cout << i << "\n";
		}
	}
	return 0;
}
