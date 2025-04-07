#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

vector<vector<ii>> G;
vector<int> A;

void dfs(int u, int p) {
	for (auto &[v, w] : G[u]) {
		if (v == p) {
			continue;
		}
		A[v] = A[u] ^ w;
		dfs(v, u);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, X{};
	cin >> N >> X;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		G[a].push_back({b, c});
		G[b].push_back({a, c});
	}
	A.resize(N + 1);
	dfs(1, -1);
	vector<int> B(20);
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 20; ++j) {
			if (A[i] & (1 << j)) {
				++B[j];
			}
		}
	}
	for (int i = 0; i < 20; ++i) {
		if (X & (1 << i)) {
			B[i] = N - B[i];
		}
	}
	int ans = 1e9;
	for (int i = 1; i <= N; ++i) {
		int sum{};
		for (int j = 0; j < 20; ++j) {
			sum += (A[i] & (1 << j)) ? N - B[j] : B[j];
		}
		ans = min(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}
