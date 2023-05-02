#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		S += S;
		int cnt{}, maxv{};
		for (char c : S) {
			if (c == '1') {
				++cnt;
			} else {
				maxv = max(maxv, cnt);
				cnt = 0;
			}
		}
		maxv = max(maxv, cnt);
		ll ans{};
		if (maxv == S.size()) {
			ans = S.size() * S.size() / 4;
		} else {
			ans = 1LL * ((maxv + 1) / 2) * (maxv / 2 + 1);
		}
		cout << ans << "\n";
	}
	return 0;
}
