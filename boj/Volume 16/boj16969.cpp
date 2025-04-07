#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1e9 + 9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	ll ans = 1;
	for (int i = 0; i < S.size(); ++i) {
		ans = ans * ((S[i] == 'c' ? 26 : 10) - (i && S[i - 1] == S[i] ? 1 : 0)) % MOD;
	}
	cout << ans << "\n";
	return 0;
}
