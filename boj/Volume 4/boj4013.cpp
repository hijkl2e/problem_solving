#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

vector<vector<int>> G, H;
stack<int> st;
vector<int> scc;

void dfs(int x, int scc_num) {
	scc[x] = scc_num == -1 ? 0 : scc_num;
	for (int y : scc_num == -1 ? G[x] : H[x]) {
		if (scc[y] == -1) {
			dfs(y, scc_num);
		}
	}
	if (scc_num == -1) {
		st.push(x);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	G.resize(N + 1);
	H.resize(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		H[v].push_back(u);
	}
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	int S{}, P{};
	cin >> S >> P;
	deque<bool> B(N + 1);
	while (P--) {
		int x{};
		cin >> x;
		B[x] = true;
	}
	scc.assign(N + 1, -1);
	for (int i = 1; i <= N; ++i) {
		if (scc[i] == -1) {
			dfs(i, -1);
		}
	}
	fill(scc.begin(), scc.end(), -1);
	int scc_num{};
	while (st.size()) {
		int x = st.top(); st.pop();
		if (scc[x] == -1) {
			dfs(x, scc_num++);
		}
	}
	vector<int> C(scc_num);
	deque<bool> D(scc_num);
	for (int i = 1; i <= N; ++i) {
		C[scc[i]] += A[i];
		D[scc[i]] |= B[i];
	}
	H.assign(scc_num, {});
	for (int u = 1; u <= N; ++u) {
		for (int v : G[u]) {
			if (scc[u] == scc[v]) {
				continue;
			}
			H[scc[u]].push_back(scc[v]);
		}
	}
	vector<ll> E(scc_num, -INF);
	E[scc[S]] = 0;
	for (int u = scc[S]; u < scc_num; ++u) {
		E[u] += C[u];
		for (int v : H[u]) {
			E[v] = max(E[v], E[u]);
		}
	}
	ll ans{};
	for (int i = scc[S]; i < scc_num; ++i) {
		if (D[i]) {
			ans = max(ans, E[i]);
		}
	}
	cout << ans << "\n";
	return 0;
}
