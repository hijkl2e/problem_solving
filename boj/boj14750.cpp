#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

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

struct point {
	ll x{}, y{};
};

bool operator<=(point &p1, point &p2) {
	return p1.x < p2.x || (p1.x == p2.x && p1.y <= p2.y);
}

int ccw(point &p1, point &p2, point &p3) {
	ll res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	return res > 0 ? 1 : res < 0 ? -1 : 0;
}

bool solve(vector<point> &A) {
	static vector<int> B(4);
	for (int i = 0; i < 4; ++i) {
		B[i] = ccw(A[i & 2], A[(i & 2) | 1], A[i ^ 2]);
	}
	point h = A[3];
	for (int i = 0; i < 4; i += 2) {
		if (A[i + 1] <= A[i]) {
			swap(A[i], A[i + 1]);
		}
	}
	if (B[1] == 0 && A[0] <= h && h <= A[1]) {
		return false;
	}
	if (count(B.begin(), B.end(), 0) == 4) {
		return A[0] <= A[3] && A[2] <= A[1];
	} else {
		return B[0] * B[1] < 1 && B[2] * B[3] < 1;
	}
}

bool solve(vector<point> &A, point &m, point &h) {
	static vector<point> B(4);
	for (int i = 0; i < A.size(); ++i) {
		int j = (i + 1) % A.size();
		B = {A[i], A[j], m, h};
		if (solve(B)) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, H{}, M{};
	cin >> N >> K >> H >> M;
	vector<point> A(N);
	vector<point> B(H);
	vector<point> C(M);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].x >> A[i].y;
	}
	for (int i = 0; i < H; ++i) {
		cin >> B[i].x >> B[i].y;
	}
	for (int i = 0; i < M; ++i) {
		cin >> C[i].x >> C[i].y;
	}
	MF mf(M + H + 2);
	for (int i = 0; i < M; ++i) {
		mf.add_edge(M + H, i, 1);
	}
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < H; ++j) {
			if (solve(A, C[i], B[j])) {
				mf.add_edge(i, M + j, 1);
			}
		}
	}
	for (int i = 0; i < H; ++i) {
		mf.add_edge(M + i, M + H + 1, K);
	}
	cout << (mf.dinic(M + H, M + H + 1) == M ? "Possible" : "Impossible") << "\n";
	return 0;
}
