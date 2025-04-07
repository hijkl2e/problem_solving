#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> A;

void dfs(int x) {
	for (int y : G[x]) {
		A[y] += A[x];
		dfs(y);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	G.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		int p{};
		cin >> p;
		if (i > 1) {
			G[p].push_back(i);
		}
	}
	A.resize(N + 1);
	while (M--) {
		int x{}, y{};
		cin >> x >> y;
		A[x] += y;
	}
	dfs(1);
	for (int i = 1; i <= N; ++i) {
		cout << A[i] << (i == N ? "\n" : " ");
	}
	return 0;
}
