#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> C;
deque<bool> A;

bool dfs(int c, int x) {
	C[x] = c;
	for (int y : G[x]) {
		if (C[y] == -1) {
			A[y] = !A[x];
		}
		if (A[x] == A[y] || (C[y] == -1 && !dfs(c, y))) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	G.resize(N + 1);
	while (M--) {
		int K{};
		cin >> K;
		int u{}, v{};
		while (K--) {
			cin >> v;
			if (u) {
				G[u].push_back(v);
				G[v].push_back(u);
			}
			u = v;
		}
	}
	C.resize(N + 1, -1);
	A.resize(N + 1);
	bool flag{};
	int cnt{};
	for (int i = 1; i <= N; ++i) {
		if (C[i] == -1 && !dfs(cnt++, i)) {
			flag = true;
			break;
		}
	}
	if (flag) {
		cout << "impossible\n";
		return 0;
	}
	vector<int> B(cnt);
	for (int i = 1; i <= N; ++i) {
		B[C[i]] += A[i] ? -1 : 1;
	}
	vector<int> D(N + 1);
	for (int i = 0; i < cnt; ++i) {
		++D[abs(B[i])];
	}
	for (int i = 1; i <= N / 2; ++i) {
		int x = (D[i] - 1) / 2;
		D[i] -= 2 * x;
		D[2 * i] += x;
	}
	B.clear();
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < D[i]; ++j) {
			B.push_back(i);
		}
	}
	int sum = accumulate(B.begin(), B.end(), 0);
	bitset<500001> dp;
	dp[0] = true;
	for (int i = 0; i < B.size(); ++i) {
		dp |= (dp << B[i]);
	}
	int ans{};
	for (int i = 0; i <= sum / 2; ++i) {
		if (dp[sum / 2 - i]) {
			ans = 2 * i + sum % 2;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
