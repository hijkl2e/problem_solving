#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<int>> G;
vector<int> A, B;

void dfs(int u, int x, int p) {
	if (u == x) {
		copy(A.begin(), A.end(), back_inserter(B));
	}
	A.push_back(u);
	for (int v : G[u]) {
		if (v == p) {
			continue;
		}
		dfs(v, x, u);
	}
	A.pop_back();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, S{}, C{}, H{};
	cin >> N >> S >> C >> H;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(S, C, -1);
	dfs(C, H, -1);
	B.push_back(H);
	vector<int> D(N + 1, -1);
	ll cnt1{}, cnt2{};
	for (int i = 0; i < B.size(); ++i) {
		if (D[B[i]] == -1) {
			D[B[i]] = i;
			++cnt1;
		} else {
			cnt2 = (i - D[B[i]]) / 2 + 1;
		}
	}
	ll ans = cnt1 * (cnt1 - 1) / 2 + cnt2 * (cnt2 - 1) / 2;
	cout << ans << "\n";
	return 0;
}
