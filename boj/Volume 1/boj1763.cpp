#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, R{};
	cin >> N >> R;
	vector<int> C(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> C[i];
	}
	vector<int> P(N + 1, -1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		P[v] = u;
	}
	vector<int> A(N + 1, 1);
	vector<int> B(N + 1);
	int ans = accumulate(C.begin(), C.end(), 0);
	for (int i = 0; i < N - 1; ++i) {
		int x{};
		for (int j = 1; j <= N; ++j) {
			if (j == R) {
				continue;
			}
			if (C[x] * 1.0 / A[x] < C[j] * 1.0 / A[j]) {
				x = j;
			}
		}
		int p = P[x];
		ans += A[p] * C[x];
		for (int j = 1; j <= N; ++j) {
			if (P[j] == x) {
				P[j] = p;
			}
		}
		C[p] += C[x];
		A[p] += A[x];
		C[x] = -1;
	}
	cout << ans << "\n";
	return 0;
}
