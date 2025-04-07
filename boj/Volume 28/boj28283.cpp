#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, X{}, Y{};
	cin >> N >> M >> X >> Y;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> G(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<int> B(Y);
	for (int i = 0; i < Y; ++i) {
		cin >> B[i];
	}
	vector<int> D(N + 1, -1);
	queue<int> q;
	for (int i = 0; i < Y; ++i) {
		D[B[i]] = 0;
		q.push(B[i]);
	}
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : G[x]) {
			if (D[y] == -1) {
				D[y] = D[x] + 1;
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (D[i] == -1 && A[i]) {
			cout << "-1\n";
			return 0;
		}
	}
	vector<ll> C(N + 1);
	for (int i = 1; i <= N; ++i) {
		C[i] = 1LL * D[i] * A[i];
	}
	sort(C.rbegin(), C.rend());
	ll ans = accumulate(C.begin(), C.begin() + X, 0LL);
	cout << ans << "\n";
	return 0;
}
