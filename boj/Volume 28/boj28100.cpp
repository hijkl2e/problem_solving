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
	vector<ll> A(2 * N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	G.resize(N + 1);
	H.resize(N + 1);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		H[v].push_back(u);
	}
	int a{}, x{}, y{};
	cin >> a >> x >> y;
	for (int i = 1; i <= N; ++i) {
		A[N + i] = A[i];
	}
	ll ans{};
	for (int z = 0; z < 2; ++z) {
		if (z == 1) {
			G.resize(2 * N + 1);
			H.resize(2 * N + 1);
			for (int i = 1; i <= N; ++i) {
				for (int x : G[i]) {
					G[N + i].push_back(N + x);
					H[N + x].push_back(N + i);
				}
			}
			G[a].push_back(N + a);
			H[N + a].push_back(a);
			G[N + x].push_back(N + y);
			H[N + y].push_back(N + x);
			G[N + y].push_back(N + x);
			H[N + x].push_back(N + y);
			N *= 2;
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
		vector<ll> B(scc_num);
		for (int i = 1; i <= N; ++i) {
			B[scc[i]] += A[i];
		}
		if (z == 1) {
			int n = N / 2;
			for (int i = 1; i <= n; ++i) {
				if (scc[n + i] == scc[n + a]) {
					B[scc[i]] -= A[i];
				}
			}
		}
		vector<vector<int>> F(scc_num);
		for (int i = 1; i <= N; ++i) {
			for (int x : G[i]) {
				if (scc[i] < scc[x]) {
					F[scc[i]].push_back(scc[x]);
				}
			}
		}
		vector<ll> C(scc_num, -INF);
		C[scc[1]] = 0;
		for (int i = 0; i < scc_num; ++i) {
			C[i] += B[i];
			for (int x : F[i]) {
				C[x] = max(C[x], C[i]);
			}
		}
		ans = max(ans, *max_element(C.begin(), C.end()));
	}
	cout << ans << "\n";
	return 0;
}
