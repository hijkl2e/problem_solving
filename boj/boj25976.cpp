#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

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
	ii ans;
	for (int i = 0; i < (1 << N); ++i) {
		if (__builtin_popcount(i) != K) {
			continue;
		}
		fill(vst.begin(), vst.end(), false);
		ii cnt;
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				cnt.first += A[j] == 1;
				cnt.second += A[j] == 2;
				vst[j] = true;
			}
		}
		for (int j = 0; j < N; ++j) {
			if ((i & (1 << j)) && j && !vst[P[j]]) {
				cnt.first = -1;
				break;
			}
		}
		int x = ans.first * ans.second;
		int y = cnt.first * cnt.second;
		if (x < y) {
			ans = cnt;
		} else if (x == y) {
			ans = max(ans, cnt);
		}
	}
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}
