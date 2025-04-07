#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct point {
	ll x{}, y{};
};

int ccw(point &p1, point &p2, point &p3) {
	ll res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
	res -= p1.y * p2.x + p2.y * p3.x + p3.y * p1.x;
	return res > 0 ? 1 : res < 0 ? -1 : 0;
}

bool solve(point &p1, point &p2, point &p3, point &p4) {
	return ccw(p1, p2, p3) * ccw(p1, p2, p4) == -1
		&& ccw(p3, p4, p1) * ccw(p3, p4, p2) == -1;
}

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

void add_edge(int u, int v) {
	G[u ^ 1].push_back(v);
	G[v ^ 1].push_back(u);
	H[v].push_back(u ^ 1);
	H[u].push_back(v ^ 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	N *= 3;
	vector<point> A(2 * N);
	for (int i = 0; i < A.size(); ++i) {
		cin >> A[i].x >> A[i].y;
	}
	G.resize(2 * N);
	H.resize(2 * N);
	for (int i = 0; i < A.size(); i += 2) {
		for (int j = i + 2; j < A.size(); j += 2) {
			if (solve(A[i], A[i + 1], A[j], A[j + 1])) {
				add_edge(i, j);
			}
		}
	}
	for (int i = 0; i < A.size(); i += 6) {
		add_edge(i + 1, i + 3);
		add_edge(i + 3, i + 5);
		add_edge(i + 5, i + 1);
	}
	scc.assign(2 * N, -1);
	for (int i = 0; i < 2 * N; ++i) {
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
	vector<int> B;
	bool yes = true;
	for (int i = 0; i < N; ++i) {
		if (scc[2 * i] == scc[2 * i + 1]) {
			yes = false;
			break;
		} else if (scc[2 * i] > scc[2 * i + 1]) {
			B.push_back(i + 1);
		}
	}
	if (yes) {
		cout << B.size() << "\n";
		for (int i = 0; i < B.size(); ++i) {
			cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
		}
	} else {
		cout << "-1\n";
	}
	return 0;
}
