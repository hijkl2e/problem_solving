#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> P(N);
	vector<int> T(M);
	for (int i = 0; i < N; ++i) {
		cin >> P[i];
	}
	for (int i = 0; i < M; ++i) {
		cin >> T[i];
	}
	sort(T.begin(), T.end());
	deque<bool> vst(M);
	for (int i = 0; i < N; ++i) {
		int idx = lower_bound(T.begin(), T.end(), P[i]) - T.begin();
		if (idx && (idx == T.size() || T[idx] - P[i] >= P[i] - T[idx - 1])) {
			--idx;
		}
		vst[idx] = true;
	}
	int ans = N - accumulate(vst.begin(), vst.end(), 0);
	cout << ans << "\n";
	return 0;
}
