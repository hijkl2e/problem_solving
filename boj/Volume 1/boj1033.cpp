#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

vector<vector<iii>> G;
vector<int> A;

int dfs1(int u, int p) {
	int ret = 1;
	for (auto &[v, d, n] : G[u]) {
		if (v == p) {
			continue;
		}
		ret *= d * dfs1(v, u);
	}
	return ret;
}

void dfs2(int u, int p) {
	for (auto &[v, d, n] : G[u]) {
		if (v == p) {
			continue;
		}
		A[v] = A[u] / d * n;
		dfs2(v, u);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N);
	for (int i = 0; i < N - 1; ++i) {
		int a{}, b{}, p{}, q{};
		cin >> a >> b >> p >> q;
		G[a].push_back({b, p, q});
		G[b].push_back({a, q, p});
	}
	A.resize(N);
	A[0] = dfs1(0, -1);
	dfs2(0, -1);
	int g = A[0];
	for (int i = 0; i < N; ++i) {
		g = gcd(g, A[i]);
	}
	for (int i = 0; i < N; ++i) {
		A[i] /= g;
	}
	for (int i = 0; i < N; ++i) {
		cout << A[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
