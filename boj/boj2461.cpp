#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	set<ii> S;
	for (int i = 0; i < N; ++i) {
		sort(A[i].begin(), A[i].end());
		S.insert({A[i][0], i});
	}
	vector<int> B(N);
	int ans = 1e9;
	while (true) {
		auto &[v, t] = *S.begin();
		ans = min(ans, S.rbegin()->first - v);
		if (++B[t] == M) {
			break;
		}
		S.insert({A[t][B[t]], t});
		S.erase(S.begin());
	}
	cout << ans << "\n";
	return 0;
}
