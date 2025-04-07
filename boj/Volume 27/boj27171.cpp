#include <bits/stdc++.h>

using namespace std;

vector<int> A{
	20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5
};

int solve(vector<int> &dp, vector<int> &B, int x, int y) {
	int ret{};
	for (int i = 0; i < 9; ++i) {
		int z = x - (i / 3 + 1) * A[(y + 19 + i % 3) % 20];
		if (z > 0 || (z == 0 && i / 3 == 1)) {
			ret += B[i] * dp[z];
		}
	}
	ret += B[9] * dp[x];
	return ret;
}

void solve(vector<int> &dp, vector<int> &B, const string &b, int x, int &y, string &z) {
	for (int i = 0; i < 20; ++i) {
		int res = solve(dp, B, x, i);
		string s = b + to_string(A[i]);
		if (y < res) {
			y = res;
			z = s;
		} else if (y == res) {
			z = min(z, s);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int Q{}, a1{}, a2{}, b1{}, b2{}, b3{}, c1{}, c2{}, d1{}, e1{};
	cin >> Q >> a1 >> a2 >> b1 >> b2 >> b3 >> c1 >> c2 >> d1 >> e1;
	e1 = 100 - e1;
	vector<vector<int>> dp(4, vector<int>(181));
	vector<vector<string>> par(4, vector<string>(181));
	vector<int> B(10);
	dp[0][0] = 1;
	for (int i = 1; i < dp.size(); ++i) {
		dp[i][0] = 100 * dp[i - 1][0];
		for (int j = 1; j < dp[i].size(); ++j) {
			int &y = dp[i][j];
			string &z = par[i][j];
			fill(B.begin(), B.end(), 0);
			B[7] = a1;
			B[6] = B[8] = a2;
			B[1] = 100 - a1 - 2 * a2;
			solve(dp[i - 1], B, "Triple ", j, y, z);
			fill(B.begin(), B.end(), 0);
			B[4] = b1;
			B[3] = B[5] = b2;
			B[1] = b3;
			B[9] = 100 - b1 - 2 * b2 - b3;
			solve(dp[i - 1], B, "Double ", j, y, z);
			fill(B.begin(), B.end(), 0);
			B[1] = c1;
			B[0] = B[2] = c2;
			B[4] = 100 - c1 - 2 * c2;
			solve(dp[i - 1], B, "Single ", j, y, z);
			for (int p : {d1, e1}) {
				int res = p * (j > 25 ? dp[i - 1][j - 25] : 0)
						+ (100 - p) * (j >= 50 ? dp[i - 1][j - 50] : 0);
				string s = p == e1 ? "Double Bull" : "Single Bull";
				if (y < res) {
					y = res;
					z = s;
				} else if (y == res) {
					z = min(z, s);
				}
			}
		}
	}
	while (Q--) {
		int S{}, N{};
		cin >> S >> N;
		cout << (dp[N][S] ? par[N][S] : "Impossible") << "\n";
	}
	return 0;
}
