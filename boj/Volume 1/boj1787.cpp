#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	vector<int> pi = get_pi(S);
	vector<int> dp(pi.begin(), pi.end());
	ll ans{};
	for (int i = 0; i < N; ++i) {
		if (pi[i] && pi[pi[i] - 1]) {
			dp[i] = dp[pi[i] - 1];
		}
		if (dp[i]) {
			ans += i - dp[i] + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
