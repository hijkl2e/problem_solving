#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

vector<int> A, B, C, D;

void dfs(int x) {
	if (B[x] != -1) {
		dfs(B[x]);
	}
	D.push_back(A[x]);
	if (C[x] != -1) {
		dfs(C[x]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	A.resize(N + 1);
	B.resize(N + 1);
	C.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i] >> B[i] >> C[i];
	}
	vector<vector<int>> nCr(M + 1, vector<int>(M + 1));
	for (int i = 0; i <= M; ++i) {
		nCr[i][0] = nCr[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
		}
	}
	D.push_back(0);
	dfs(1);
	D.push_back(M + 1);
	ll ans = 1;
	for (int i = 0, j = 1; i < D.size() - 1; i = j++) {
		while (D[j] == -1) {
			++j;
		}
		ans = ans * nCr[D[j] - D[i] - 1][j - i - 1] % MOD;
	}
	cout << ans << "\n";
	return 0;
}
