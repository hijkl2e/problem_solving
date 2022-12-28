#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(9);
	for (int i = 0; i < 9; ++i) {
		cin >> A[i];
	}
	auto it = max_element(A.begin(), A.end());
	cout << *it << "\n" << (it - A.begin() + 1) << "\n";
	return 0;
}
