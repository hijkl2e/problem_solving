#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

vector<vector<ii>> G;
vector<int> A, vst;
vector<ll> B, C;

void dfs(int u) {
	vst[u] = 1;
	for (auto &[v, w] : G[u]) {
		if (vst[v] == -1) {
			A[v] = A[u];
			B[v] = B[u] + w;
			dfs(v);
		} else if (vst[v] == 1) {
			C.back() = gcd(C.back(), B[u] - B[v] + w);
		}
	}
	vst[u] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, Q{};
	cin >> N >> M >> Q;
	G.resize(N + 1);
	while (M--) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	A.resize(N + 1);
	B.resize(N + 1);
	vst.assign(N + 1, -1);
	for (int i = 1; i <= N; ++i) {
		if (vst[i] == -1) {
			A[i] = C.size();
			C.push_back(0);
			dfs(i);
		}
	}
	while (Q--) {
		int u{}, v{}, k{};
		cin >> u >> v >> k;
		bool yes = A[u] == A[v] && (B[u] + B[v]) % gcd(C[A[u]], k) == 0;
		cout << (yes ? "Yes" : "No") << "\n";
	}
	return 0;
}
