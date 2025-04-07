#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	char s{}, e{};
	cin >> s >> e;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<vector<int>> G(N);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		--u, --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<int> D(N, INF);
	vector<vector<int>> par(N);
	queue<int> q;
	for (int i = 0; i < N; ++i) {
		if (S[i] == e) {
			D[i] = 0;
			q.push(i);
		}
	}
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y : G[x]) {
			if (D[y] == INF) {
				D[y] = D[x] + 1;
				par[y].push_back(x);
				q.push(y);
			} else if (D[y] == D[x] + 1) {
				par[y].push_back(x);
			}
		}
	}
	int minv = INF;
	vector<int> A;
	for (int i = 0; i < N; ++i) {
		if (S[i] != s) {
			continue;
		}
		if (minv > D[i]) {
			minv = D[i];
			A.clear();
		}
		if (minv == D[i]) {
			A.push_back(i);
		}
	}
	if (minv == INF) {
		cout << "Aaak!\n";
		return 0;
	}
	string ans;
	while (par[A[0]].size()) {
		ans += S[A[0]];
		char c = 'Z';
		vector<int> B;
		for (int x : A) {
			for (int p : par[x]) {
				if (c > S[p]) {
					c = S[p];
					B.clear();
				}
				if (c == S[p]) {
					B.push_back(p);
				}
			}
		}
		sort(B.begin(), B.end());
		B.resize(unique(B.begin(), B.end()) - B.begin());
		swap(A, B);
	}
	ans += S[A[0]];
	cout << ans << "\n";
	return 0;
}
