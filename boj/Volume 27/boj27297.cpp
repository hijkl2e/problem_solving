#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<ll>> P(N, vector<ll>(M));
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> P[j][i];
		}
	}
	for (int i = 0; i < N; ++i) {
		sort(P[i].begin(), P[i].end());
	}
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		if (M % 2) {
			A[i] = P[i][M / 2];
		} else {
			A[i] = (P[i][M / 2 - 1] + P[i][M / 2]) / 2;
		}
	}
	ll ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			ans += abs(A[i] - P[i][j]);
		}
	}
	cout << ans << "\n";
	for (int i = 0; i < N; ++i) {
		cout << A[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
