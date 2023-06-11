#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int ans{};
	for (int i = 0; i < (1 << K); ++i) {
		int minv = 1e9;
		for (int j = 0; j < N; ++j) {
			int cnt{};
			for (int k = 0; k < K; ++k) {
				if (((i >> k) & 1) ^ (A[j][k] == 'F')) {
					++cnt;
				}
			}
			minv = min(minv, cnt);
		}
		ans = max(ans, minv);
	}
	cout << ans << "\n";
	return 0;
}
