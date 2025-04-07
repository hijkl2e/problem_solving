#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(26);
	string rock = "ROCK";
	for (int i = 0; i < rock.size(); ++i) {
		A[rock[i] - 'A'] = 4 - i;
	}
	ll N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	reverse(S.begin(), S.end());
	vector<ll> dp(5);
	dp[0] = 1;
	for (char c : S) {
		dp[4] = 2 * dp[4] % MOD;
		int j = A[c - 'A'];
		if (j) {
			dp[j] = (dp[j] + dp[j - 1]) % MOD;
		}
	}
	cout << dp[4] << "\n";
	return 0;
}
