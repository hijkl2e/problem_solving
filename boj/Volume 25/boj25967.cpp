#include <bits/stdc++.h>

using namespace std;

vector<int> X, Y;

int dist(int a, int b) {
	a -= 'A';
	b -= 'A';
	return (X[b] - X[a]) * (X[b] - X[a]) + (Y[b] - Y[a]) * (Y[b] - Y[a]);
}

int solve(string &s1, string &s2) {
	static vector<vector<int>> dp(501, vector<int>(501));
	for (int i = 0; i <= s1.size(); ++i) {
		dp[i][0] = i * 1600;
	}
	for (int i = 0; i <= s2.size(); ++i) {
		dp[0][i] = i * 1600;
	}
	for (int i = 1; i <= s1.size(); ++i) {
		for (int j = 1; j <= s2.size(); ++j) {
			dp[i][j] = dp[i - 1][j - 1] + dist(s1[i - 1], s2[j - 1]);
			dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - 1]) + 1600);
		}
	}
	return dp[s1.size()][s2.size()];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> key{
		"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"
	};
	X.resize(26);
	Y.resize(26);
	for (int i = 0; i < 3; ++i) {
		int x = (1 << i) - 1;
		int y = 4 * i;
		for (int j = 0; j < key[i].size(); ++j) {
			X[key[i][j] - 'A'] = x + 4 * j;
			Y[key[i][j] - 'A'] = y;
		}
	}
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> W(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, W[i]);
	}
	string T;
	getline(cin, T);
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		A[i] = solve(W[i], T);
	}
	int minv = *min_element(A.begin(), A.end());
	vector<string> B;
	for (int i = 0; i < N; ++i) {
		if (A[i] == minv) {
			B.push_back(W[i]);
		}
	}
	sort(B.begin(), B.end());
	for (auto &s : B) {
		cout << s << "\n";
	}
	return 0;
}
