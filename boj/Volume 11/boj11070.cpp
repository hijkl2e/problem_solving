#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		vector<int> A(N + 1);
		vector<int> B(N + 1);
		while (M--) {
			int a{}, b{}, p{}, q{};
			cin >> a >> b >> p >> q;
			A[a] += p;
			B[a] += q;
			A[b] += q;
			B[b] += p;
		}
		int maxv = 0, minv = 1000;
		for (int i = 1; i <= N; ++i) {
			int x{};
			if (A[i] || B[i]) {
				A[i] *= A[i];
				B[i] *= B[i];
				x = 1000LL * A[i] / (A[i] + B[i]);
			}
			maxv = max(maxv, x);
			minv = min(minv, x);
		}
		cout << maxv << "\n";
		cout << minv << "\n";
	}
	return 0;
}
