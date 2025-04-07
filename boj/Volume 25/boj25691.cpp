#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> P(N, -1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		P[v] = u;
	}
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	deque<bool> vst(N);
	int ans{};
	for (int i = 0; i < (1 << N); ++i) {
		if (__builtin_popcount(i) != K) {
			continue;
		}
		fill(vst.begin(), vst.end(), false);
		int cnt{};
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				cnt += A[j];
				vst[j] = true;
			}
		}
		for (int j = 0; j < N; ++j) {
			if ((i & (1 << j)) && j && !vst[P[j]]) {
				cnt = -1;
				break;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
