#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(11);
	for (int i = 0; i < 2047; ++i) {
		for (int j = 0; j < 11; ++j) {
			int x{};
			cin >> x;
			A[j] ^= x;
		}
	}
	for (int i = 0; i < 11; ++i) {
		cout << A[i] << (i == 10 ? "\n" : " ");
	}
	return 0;
}
