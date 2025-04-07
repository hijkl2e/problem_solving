#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int F{};
	cin >> F;
	F *= 100;
	vector<int> A;
	int x{};
	while (cin >> x, x) {
		A.push_back(x);
	}
	A.resize(min<int>(A.size(), 200));
	int n = A.size();
	vector<vector<int>> dp(n + 1, vector<int>(2 * F + 1, -1));
	dp[0][F] = F;
	int sum{};
	for (int i = 0; i < n; ++i) {
		bool flag{};
		for (int j = 0; j < dp[i].size(); ++j) {
			if (dp[i][j] == -1) {
				continue;
			}
			int x = (sum - j + F) / 2;
			int y = (sum + j - F) / 2;
			if (x + A[i] <= F) {
				dp[i + 1][j - A[i]] = j;
				flag = true;
			}
			if (y + A[i] <= F) {
				dp[i + 1][j + A[i]] = j;
				flag = true;
			}
		}
		if (!flag) {
			dp.resize(i + 1);
			break;
		}
		sum += A[i];
	}
	int p{};
	while (dp.back()[p] == -1) {
		++p;
	}
	stack<bool> st;
	for (int i = dp.size() - 1; i > 0; --i) {
		st.push(dp[i][p] > p);
		p = dp[i][p];
	}
	cout << st.size() << "\n";
	while (st.size()) {
		cout << (st.top() ? "port" : "starboard") << "\n";
		st.pop();
	}
	return 0;
}
