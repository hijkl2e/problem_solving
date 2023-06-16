#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(1e6);
	for (int k = 1; k < 3; ++k) {
		int N{};
		cin >> N;
		while (N--) {
			int x{};
			cin >> x;
			A[x] |= k;
		}
	}
	int ans{}, p{};
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] && (A[i] == 3 || p != A[i])) {
			++ans;
			p = A[i];
		}
	}
	cout << ans << "\n";
	return 0;
}
