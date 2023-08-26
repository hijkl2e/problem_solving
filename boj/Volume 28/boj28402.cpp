#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int INF = 1e9 + 7;

template <typename T = ll>
class Seg {
public:
	Seg() { }
	Seg(int sz) : n(sz), st(2 * sz) { }
	Seg(vector<T> &A) : n(A.size()), st(2 * A.size()) {
		copy(A.begin(), A.end(), st.begin() + n);
		for (int i = n - 1; i > 0; --i) {
			st[i] = max(st[2 * i], st[2 * i + 1]);
		}
	}
	void update(int p, T val) {
		for (st[p += n] = val; p > 1; p /= 2) {
			st[p / 2] = max(st[p], st[p ^ 1]);
		}
	}
	T rmq(int l, int r) {
		T ret = -INF;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				ret = max(ret, st[l++]);
			}
			if (r & 1) {
				ret = max(st[--r], ret);
			}
		}
		return ret;
	}
private:
	int n;
	vector<T> st;
};

template <typename T = ll>
class MergeT {
public:
	MergeT(vector<ii> &B) : n(B.size()), A(2 * B.size()), st(2 * B.size()) {
		for (int i = 0; i < n; ++i) {
			A[i + n].push_back(B[i]);
			st[i + n] = Seg(1);
			st[i + n].update(0, B[i].second);
		}
		for (int i = n - 1; i > 0; --i) {
			int l = 2 * i;
			int r = 2 * i + 1;
			merge(A[l].begin(), A[l].end(), A[r].begin(), A[r].end(),
					back_inserter(A[i]));
			vector<T> C(A[i].size());
			for (int j = 0; j < C.size(); ++j) {
				C[j] = A[i][j].second;
			}
			st[i] = Seg(C);
		}
	}
	int query(int l, int r, int s, int e) {
		int ret = -INF;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) {
				ret = max(ret, query(l++, s, e));
			}
			if (r & 1) {
				ret = max(query(--r, s, e), ret);
			}
		}
		return ret;
	}
private:
	int query(int p, int s, int e) {
		int l = lower_bound(A[p].begin(), A[p].end(), make_pair(s, -1)) - A[p].begin();
		int r = lower_bound(A[p].begin(), A[p].end(), make_pair(e, -1)) - A[p].begin();
		return st[p].rmq(l, r);
	}
	int n;
	vector<vector<ii>> A;
	vector<Seg<T>> st;
};

void dfs(vector<vector<int>> &G, int x, int p,
		vector<int> &in, vector<int> &out, int &cntr) {
	in[x] = out[x] = cntr++;
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		dfs(G, y, x, in, out, cntr);
		out[x] = out[y];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<vector<int>> G(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<vector<int>> H(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int u{}, v{};
		cin >> u >> v;
		H[u].push_back(v);
		H[v].push_back(u);
	}
	vector<int> in1(N + 1);
	vector<int> out1(N + 1);
	int cntr{};
	dfs(G, 1, -1, in1, out1, cntr);
	vector<int> in2(N + 1);
	vector<int> out2(N + 1);
	cntr = 0;
	dfs(H, 1, -1, in2, out2, cntr);
	vector<ii> B(N);
	for (int i = 1; i <= N; ++i) {
		int x = in2[i];
		B[x] = {in1[i], A[i]};
	}
	MergeT mergeT(B);
	vector<int> C(N + 1);
	for (int i = 1; i <= N; ++i) {
		C[i] = mergeT.query(in2[i], out2[i] + 1, in1[i], out1[i] + 1);
	}
	for (int i = 1; i <= N; ++i) {
		cout << C[i] << "\n";
	}
	return 0;
}
