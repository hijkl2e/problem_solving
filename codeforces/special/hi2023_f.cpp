#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G, dp1, dp2;
vector<int> A, B, sz;

void dfs1(int x) {
	sz[x] = 1;
	dp1[x][A[x]] = -2;
	for (int y : G[x]) {
		dfs1(y);
		sz[x] += sz[y];
		swap(dp1[x], dp2[y]);
		for (int i = 0; i < 32; ++i) {
			if (dp1[y][i] == -1) {
				continue;
			}
			for (int j = 0; j < 32; ++j) {
				if (dp2[y][j] == -1) {
					continue;
				}
				dp1[x][i ^ j] = i;
			}
		}
	}
	if (sz[x] % 2 == 0) {
		dp1[x][0] = -3;
	}
}

void dfs2(int x, int z) {
	if (dp1[x][z] == -3) {
		B.push_back(x);
		return;
	}
	int t = dp1[x][z];
	for (int i = G[x].size() - 1; i >= 0; --i) {
		int y = G[x][i];
		dfs2(y, t);
		z ^= t;
		t = dp2[y][z];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	G.resize(N + 1);
	for (int i = 2; i <= N; ++i) {
		int x{};
		cin >> x;
		G[x].push_back(i);
	}
	dp1.assign(N + 1, vector<int>(32, -1));
	dp2.assign(N + 1, vector<int>(32, -1));
	sz.resize(N + 1);
	dfs1(1);
	if (dp1[1][0] == -1) {
		cout << "-1\n";
		return 0;
	}
	dfs2(1, 0);
	B.push_back(1);
	cout << B.size() << "\n";
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}
