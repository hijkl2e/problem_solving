#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int solve(int x, int y, int z) {
	static vector<int> A{1, 10, 100, 1000};
	for (int i = 0; i < 3; ++i) {
		if ((y & (1 << i)) == 0) {
			continue;
		}
		int r = x % A[i + 1];
		x = x - r + (r + z * A[i] + A[i + 1]) % A[i + 1];
	}
	return x;
}

int solve(int x, int y) {
	static vector<int> A{1, 10, 100, 1000};
	for (int i = 0; i < 3; ++i) {
		int r = y % A[i + 1];
		y = y - r + (r - x % A[i + 1] + x % A[i] + A[i + 1]) % A[i + 1];
	}
	return y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> D(1001, -1);
	queue<int> q;
	D[0] = 0;
	q.push(0);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = 1; i < 8; ++i) {
			if (i == 5) {
				continue;
			}
			for (int j = -3; j < 4; ++j) {
				int y = solve(x, i, j);
				if (D[y] == -1) {
					D[y] = D[x] + 1;
					q.push(y);
				}
			}
		}
	}
	int N{};
	cin >> N;
	cin.ignore();
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	s1 += "00", s2 += "00";
	vector<vector<int>> dp(N + 1, vector<int>(101, INF));
	dp[0][stoi(s1.substr(0, 2))] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 100; ++j) {
			int x = 10 * j + s1[i + 2] - '0';
			for (int k = 0; k < 100; ++k) {
				int y = 100 * (s2[i] - '0') + k;
				dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + D[solve(x, y)]);
			}
		}
	}
	cout << dp[N][0] << "\n";
	return 0;
}
