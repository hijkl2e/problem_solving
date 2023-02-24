#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(9);
	for (int i = 0; i < 9; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int sum = accumulate(A.begin(), A.end(), 0);
	int x{}, y{};
	for (int i = 0; i < 9; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if (sum - A[i] - A[j] == 100) {
				x = i, y = j, i = 9;
				break;
			}
		}
	}
	for (int i = 0; i < 9; ++i) {
		if (i == x || i == y) {
			continue;
		}
		cout << A[i] << "\n";
	}
	return 0;
}
