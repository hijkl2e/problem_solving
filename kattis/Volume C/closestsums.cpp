#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 1; cin >> N; ++tc) {
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		vector<int> B;
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				B.push_back(A[i] + A[j]);
			}
		}
		sort(B.begin(), B.end());
		B.resize(unique(B.begin(), B.end()) - B.begin());
		cout << "Case " << tc << ":\n";
		int M{};
		cin >> M;
		while (M--) {
			int x{};
			cin >> x;
			auto it = lower_bound(B.begin(), B.end(), x);
			int ans = it == B.end() ? *--B.end() : *it;
			if (it != B.begin() && ans - x > x - *--it) {
				ans = *it;
			}
			cout << "Closest sum to " << x << " is " << ans << ".\n";
		}
	}
	return 0;
}
