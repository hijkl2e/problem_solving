#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(3);
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		++A[x + 1];
	}
	string ans;
	if (A[1] >= (N + 1) / 2) {
		ans = "INVALID";
	} else if (A[2] > A[0]) {
		ans = "APPROVED";
	} else {
		ans = "REJECTED";
	}
	cout << ans << "\n";
	return 0;
}
