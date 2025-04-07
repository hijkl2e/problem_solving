#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> C(N);
	vector<int> S(N);
	for (int i = 0; i < N; ++i) {
		cin >> C[i] >> S[i];
	}
	vector<vector<ii>> A(N + 1);
	vector<int> B(2001);
	for (int i = 0; i < N; ++i) {
		A[C[i]].push_back({S[i], 0});
		B[S[i]] += S[i];
	}
	for (int i = 1; i <= N; ++i) {
		sort(A[i].begin(), A[i].end());
		for (int j = 1; j < A[i].size(); ++j) {
			A[i][j].second = A[i][j - 1].second + A[i][j - 1].first;
		}
	}
	partial_sum(B.begin(), B.end(), B.begin());
	for (int i = 0; i < N; ++i) {
		int p = lower_bound(A[C[i]].begin(), A[C[i]].end(), make_pair(S[i], -1)) - A[C[i]].begin();
		int ans = B[S[i] - 1] - A[C[i]][p].second;
		cout << ans << "\n";
	}
	return 0;
}
