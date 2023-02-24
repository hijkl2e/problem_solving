#include <bits/stdc++.h>

using namespace std;

using cc = pair<char, char>;

int read(bitset<34040> &bs, int x) {
	int ret{};
	ret |= bs[2 * x];
	ret |= bs[2 * x + 1] << 1;
	return ret;
}

void write(bitset<34040> &bs, int x, int val) {
	bs[2 * x] = val & 1;
	bs[2 * x + 1] = val & 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S, T;
	getline(cin, S);
	getline(cin, T);
	vector<vector<int>> dp(2, vector<int>(T.size() + 1));
	vector<bitset<34040>> par(S.size() + 1);
	for (int i = 0; i <= T.size(); ++i) {
		dp[0][i] = i;
	}
	for (int i = 1; i <= S.size(); ++i) {
		dp[1][0] = i;
		for (int j = 1; j <= T.size(); ++j) {
			if (S[i - 1] == T[j - 1]) {
				dp[1][j] = dp[0][j - 1];
				continue;
			}
			dp[1][j] = min({dp[0][j - 1], dp[0][j], dp[1][j - 1]}) + 1;
			if (dp[1][j] == dp[0][j - 1] + 1) {
				write(par[i], j, 1);
			} else if (dp[0][j] < dp[1][j - 1]) {
				write(par[i], j, 2);
			} else {
				write(par[i], j, 3);
			}
		}
		copy(dp[1].begin(), dp[1].end(), dp[0].begin());
	}
	stack<cc> st;
	int p1 = S.size(), p2 = T.size();
	while (p1 && p2) {
		int val = read(par[p1], p2);
		if (val == 0) {
			st.push({'c', S[--p1]});
			--p2;
		} else if (val == 1) {
			st.push({'m', T[--p2]});
			--p1;
		} else if (val == 2) {
			st.push({'d', S[--p1]});
		} else {
			st.push({'a', T[--p2]});
		}
	}
	while (p1) {
		st.push({'d', S[--p1]});
	}
	while (p2) {
		st.push({'a', T[--p2]});
	}
	while (st.size()) {
		auto [c1, c2] = st.top(); st.pop();
		cout << c1 << " " << c2 << "\n";
	}
	return 0;
}
