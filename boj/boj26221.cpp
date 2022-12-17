#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using edge = pair<int, int>;
using query = pair<ll, int>;
using rec = tuple<ll, int, int>;

vector<vector<edge>> G;
vector<ll> A, B;

void dfs(int u, int p, int d) {
	B[u] = d;
	for (auto &[v, w] : G[u]) {
		if (v == p) {
			continue;
		}
		dfs(v, u, d + 1);
		A[v] = B[v] + w - 1;
		B[u] = max(B[u], A[v]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{}, w{};
		cin >> u >> v >> w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	A.resize(N + 1);
	B.resize(N + 1);
	dfs(1, -1, 0);
	int Q{};
	cin >> Q;
	vector<query> C(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> C[i].first;
		C[i].second = i;
	}
	sort(C.begin(), C.end());
	for (int i = Q - 1; i > 0; --i) {
		C[i].first -= C[i - 1].first;
	}
	vector<ll> D(Q);
	priority_queue<rec> pq;
	deque<bool> vst(N + 1);
	ll ans = B[1];
	vst[1] = true;
	for (auto &[v, w] : G[1]) {
		vst[v] = true;
		pq.push({A[v], 1, v});
		pq.push({B[v], -1, v});
	}
	ll x{}, cnt{};
	for (auto &[b, idx] : C) {
		x += b;
		bool flag = true;
		while (flag) {
			flag = false;
			while (pq.size()) {
				auto [d, t, u] = pq.top();
				if (d < ans) {
					break;
				}
				pq.pop();
				cnt += t;
				if (t == 1) {
					continue;
				}
				for (auto &[v, w] : G[u]) {
					if (vst[v]) {
						continue;
					}
					vst[v] = true;
					pq.push({A[v], 1, v});
					pq.push({B[v], -1, v});
				}
				if (G[u].size() == 1) {
					while (pq.size()) {
						pq.pop();
					}
				}
			}
			if (pq.empty() || x < cnt) {
				break;
			}
			auto &[d, t, u] = pq.top();
			ll y = min(ans - d, x / cnt);
			x -= cnt * y;
			ans -= y;
			flag = true;
		}
		D[idx] = ans;
	}
	for (int i = 0; i < Q; ++i) {
		cout << D[i] << "\n";
	}
	return 0;
}
