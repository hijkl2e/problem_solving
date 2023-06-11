#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int INF = 1e9 + 7;
const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

class MF {
public:
	using edge = tuple<int, ll, ll>;
	MF(int V) : G(V), d(V), last(V) { }
	void add_edge(int u, int v, ll c, bool d = true) {
		G[u].push_back(E.size());
		E.push_back({v, c, 0});
		G[v].push_back(E.size());
		E.push_back({u, d ? 0 : c, 0});
	}
	ll dinic(int s, int t) {
		ll mf{};
		while (bfs(s, t)) {
			fill(last.begin(), last.end(), 0);
			while (ll f = dfs(s, t)) {
				mf += f;
			}
		}
		return mf;
	}
private:
	bool bfs(int s, int t) {
		fill(d.begin(), d.end(), -1);
		queue<int> q;
		d[s] = 0;
		q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (int idx : G[u]) {
				auto &[v, cap, flow] = E[idx];
				if (d[v] == -1 && flow < cap) {
					d[v] = d[u] + 1;
					q.push(v);
					if (v == t) {
						return true;
					}
				}
			}
		}
		return false;
	}
	ll dfs(int u, int t, ll f = INF) {
		if (u == t) {
			return f;
		}
		for (int &i = last[u]; i < G[u].size(); ++i) {
			auto &[v, cap, flow] = E[G[u][i]];
			if (d[v] == d[u] + 1 && flow < cap) {
				if (ll pushed = dfs(v, t, min(f, cap - flow))) {
					flow += pushed;
					auto &rflow = get<2>(E[G[u][i] ^ 1]);
					rflow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}
	vector<edge> E;
	vector<vector<int>> G;
	vector<int> d, last;
};

int R, C;
vector<string> A;

vector<int> bfs(int sx, int sy) {
	vector<vector<int>> D(R, vector<int>(C, INF));
	queue<ii> q;
	D[sx][sy] = 0;
	q.push({sx, sy});
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < R && 0 <= ny && ny < C && A[nx][ny] != 'X' && D[nx][ny] == INF) {
				D[nx][ny] = D[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	vector<int> ret;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (A[i][j] == 'P') {
				ret.push_back(D[i][j]);
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> R >> C;
	cin.ignore();
	A.resize(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> B;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (A[i][j] == 'C') {
				B.push_back(bfs(i, j));
			}
		}
	}
	if (B.size() == 0) {
		cout << "0\n";
		return 0;
	}
	int sz1 = B.size(), sz2 = B[0].size();
	int lo = -1, hi = R * C;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		MF mf(sz1 + sz2 + 2);
		for (int i = 0; i < sz1; ++i) {
			mf.add_edge(sz1 + sz2, i, 1);
		}
		for (int i = 0; i < sz1; ++i) {
			for (int j = 0; j < sz2; ++j) {
				if (B[i][j] <= mid) {
					mf.add_edge(i, sz1 + j, 1);
				}
			}
		}
		for (int i = 0; i < sz2; ++i) {
			mf.add_edge(sz1 + i, sz1 + sz2 + 1, 1);
		}
		if (mf.dinic(sz1 + sz2, sz1 + sz2 + 1) == sz1) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << (hi == R * C ? -1 : hi) << "\n";
	return 0;
}
