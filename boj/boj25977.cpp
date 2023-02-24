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
	K = min<int>(K, count(A.begin(), A.end(), 1));
	deque<bool> vst(N);
	int ans{};
	for (int i = 0; i < (1 << N); ++i) {
		fill(vst.begin(), vst.end(), false);
		int cnt1{}, cnt2{};
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				cnt1 += A[j] == 1;
				cnt2 += A[j] == 2;
				vst[j] = true;
			}
		}
		if (cnt1 != K) {
			continue;
		}
		for (int j = 0; j < N; ++j) {
			if ((i & (1 << j)) && j && !vst[P[j]]) {
				cnt2 = -1;
				break;
			}
		}
		ans = max(ans, cnt2);
	}
	cout << ans << "\n";
	return 0;
}
