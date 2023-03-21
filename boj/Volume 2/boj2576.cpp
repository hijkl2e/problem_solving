#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A;
	for (int i = 0; i < 7; ++i) {
		int x{};
		cin >> x;
		if (x % 2) {
			A.push_back(x);
		}
	}
	sort(A.begin(), A.end());
	if (A.size()) {
		cout << accumulate(A.begin(), A.end(), 0) << "\n";
		cout << A[0] << "\n";
	} else {
		cout << "-1\n";
	}
	return 0;
}
