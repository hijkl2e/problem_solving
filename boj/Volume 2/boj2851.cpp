#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(10);
	for (int i = 0; i < 10; ++i) {
		cin >> A[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	auto it = lower_bound(A.begin(), A.end(), 100);
	if (it == A.end() || (it != A.begin() && 100 - *prev(it) < *it - 100)) {
		--it;
	}
	cout << *it << "\n";
	return 0;
}
