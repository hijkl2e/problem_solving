#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e5;

string S;
vector<vector<ll>> dp;

bool match(char c1, char c2) {
	if (c1 == ')' || c1 == ']' || c1 == '}' || c2 == '(' || c2 == '[' || c2 == '{') {
		return false;
	} else if (c1 == '?' || c2 == '?') {
		return true;
	} else {
		return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}');
	}
}

ll solve(int s, int e) {
	if (dp[s][e] != -1) {
		return dp[s][e];
	} else if (s >= e) {
		return 1;
	} else if ((e - s) % 2) {
		return 0;
	}
	ll &val = dp[s][e];
	val = 0;
	for (int i = s + 1; i < e; ++i) {
		if (match(S[s], S[i])) {
			val += (S[s] == '?' && S[i] == '?' ? 3 : 1) * solve(s + 1, i) * solve(i + 1, e);
		}
	}
	if (val >= MOD) {
		val = val % MOD + MOD;
	}
	return val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	getline(cin, S);
	dp.assign(N + 1, vector<ll>(N + 1, -1));
	ll ans = solve(0, N);
	if (ans < MOD) {
		cout << ans << "\n";
	} else {
		cout << setfill('0') << setw(5) << ans % MOD << "\n";
	}
	return 0;
}
