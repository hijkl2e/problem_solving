#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N);
	for (int i = 1; i < N; ++i) {
		B[i] = (A[i] > A[i + 1]);
	}
	partial_sum(B.begin(), B.end(), B.begin());
	int Q{};
	cin >> Q;
	while (Q--) {
		int x{}, y{};
		cin >> x >> y;
		int ans = B[y - 1] - B[x - 1];
		cout << ans << "\n";
	}
	return 0;
}
