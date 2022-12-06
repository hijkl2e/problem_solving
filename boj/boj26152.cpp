#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	map<int, int> w2s;
	int prev = 1e9;
	for (int i = 0; i < N; ++i) {
		if (prev > A[i] - B[i]) {
			w2s.insert({A[i] - B[i], i});
			prev = A[i] - B[i];
		}
	}
	w2s.insert({0, N});
	int Q{};
	cin >> Q;
	while (Q--) {
		int x{};
		cin >> x;
		auto it = --w2s.lower_bound(x);
		int ans = it->second;
		cout << ans << "\n";
	}
	return 0;
}
