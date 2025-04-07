#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<vector<int>> G(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
	}
	vector<int> ind(N + 1);
	for (int i = 1; i <= N; ++i) {
		for (int x : G[i]) {
			++ind[x];
		}
	}
	vector<int> A;
	queue<int> q;
	q.push(1);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : G[x]) {
			if (--ind[y] == 0) {
				q.push(y);
			}
		}
		A.push_back(x);
	}
	vector<ll> B(N + 1);
	B[1] = 1;
	vector<ii> C;
	int L = -1;
	for (int i = 0; i < A.size(); ++i) {
		int x = A[i];
		if (L == -1 && B[x] > K) {
			L = i - 1;
		}
		if (B[x] > K) {
			B[x] %= K;
		}
		for (int y : G[x]) {
			B[y] += B[x];
		}
		if (L == -1) {
			int y = A[i + 1];
			while (2 * B[x] > B[y]) {
				B[y] += B[x];
				C.push_back({x, y});
			}
		}
	}
	K = (K - B[N]) % K;
	while (K) {
		while (K >= B[A[L]]) {
			K -= B[A[L]];
			C.push_back({A[L], N});
		}
		--L;
	}
	cout << C.size() << "\n";
	for (auto &p : C) {
		cout << p.first << " " << p.second << "\n";
	}
	return 0;
}
