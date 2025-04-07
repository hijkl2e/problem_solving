#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

int N;
vector<vector<ll>> D;
vector<ll> F, A, B;

ll solve(int i, int j) {
	return B[i] + F[A[i]] + (j < N ? D[A[i]][A[j + 1]] + B[N] - B[j + 1] : 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, R{};
	cin >> N >> M >> R;
	D.assign(M + 1, vector<ll>(M + 1));
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> D[i][j];
		}
	}
	for (int k = 1; k <= M; ++k) {
		for (int i = 1; i <= M; ++i) {
			for (int j = 1; j <= M; ++j) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
	F.resize(M + 1);
	for (int i = 1; i <= M; ++i) {
		cin >> F[i];
	}
	A.resize(N + 1);
	A[0] = 1;
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	B.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		B[i] = D[A[i - 1]][A[i]];
	}
	partial_sum(B.begin(), B.end(), B.begin());
	int lo = -1, hi = N;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		bool yes{};
		for (int i = 1; i + mid <= N; ++i) {
			if (solve(i, i + mid) <= R) {
				yes = true;
				break;
			}
		}
		if (yes) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	ll ans = INF;
	for (int i = 1; i + hi <= N; ++i) {
		ans = min(ans, solve(i, i + hi));
	}
	if (ans == INF) {
		cout << "-1\n";
	} else {
		cout << hi << " " << ans << "\n";
	}
	return 0;
}
