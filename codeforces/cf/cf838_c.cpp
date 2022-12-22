#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cin.ignore();
		string S;
		getline(cin, S);
		ll ans = 1, cnt = 1;
		for (int i = 1; i < S.size(); ++i) {
			if (S[i - 1] == S[i]) {
				cnt = 2 * cnt % MOD;
			} else {
				cnt = 1;
			}
			ans = (ans + cnt) % MOD;
		}
		cout << ans << "\n";
	}
	return 0;
}
