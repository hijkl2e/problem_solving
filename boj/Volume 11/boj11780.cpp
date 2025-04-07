#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

vector<vector<int>> D, par;
vector<int> A;

void solve(int u, int v) {
	if (par[u][v] == -1) {
		A.push_back(u);
		return;
	}
	solve(u, par[u][v]);
	solve(par[u][v], v);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	D.assign(N + 1, vector<int>(N + 1, INF));
	for (int i = 1; i <= N; ++i) {
		D[i][i] = 0;
	}
	while (M--) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		D[a][b] = min(D[a][b], c);
	}
	par.assign(N + 1, vector<int>(N + 1, -1));
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				int nd = D[i][k] + D[k][j];
				if (D[i][j] > nd) {
					D[i][j] = nd;
					par[i][j] = k;
				}
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cout << (D[i][j] == INF ? 0 : D[i][j]) << (j == N ? "\n" : " ");
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (i == j || D[i][j] == INF) {
				cout << "0\n";
				continue;
			}
			A.clear();
			solve(i, j);
			A.push_back(j);
			cout << A.size();
			for (int x : A) {
				cout << " " << x;
			}
			cout << "\n";
		}
	}
	return 0;
}
