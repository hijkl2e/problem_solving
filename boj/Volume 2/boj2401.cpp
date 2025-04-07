#include <bits/stdc++.h>

using namespace std;

vector<int> get_pi(string &s) {
	vector<int> pi(s.size());
	for (int i = 1; i < pi.size(); ++i) {
		int j = pi[i - 1];
		while (j && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}

vector<int> kmp(string &s, string &p) {
	vector<int> ret;
	vector<int> pi = get_pi(p);
	for (int i = 0, j = 0; i < s.size(); ++i) {
		while (j && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j] && ++j == p.size()) {
			ret.push_back(i - j + 1);
			j = pi[j - 1];
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<bitset<501>> B(S.size() + 1);
	for (int i = 0; i < N; ++i) {
		vector<int> res = kmp(S, A[i]);
		for (int x : res) {
			B[x + A[i].size()][i] = true;
		}
	}
	vector<int> dp(S.size() + 1);
	for (int i = 1; i < dp.size(); ++i) {
		dp[i] = dp[i - 1];
		for (int j = 0; j < N; ++j) {
			if (B[i][j]) {
				int sz = A[j].size();
				dp[i] = max(dp[i], dp[i - sz] + sz);
			}
		}
	}
	cout << dp.back() << "\n";
	return 0;
}
