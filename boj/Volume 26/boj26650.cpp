#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	ll ans{}, cnt1{}, cnt2{};
	for (int i = 0; i < S.size(); ++i) {
		if (cnt1 && (S[i] == S[i - 1] || S[i] - S[i - 1] == 1)) {
			if (S[i] == 'A') {
				++cnt1;
			} else if (S[i] == 'Z') {
				++cnt2;
			}
		} else {
			ans += cnt1 * cnt2;
			cnt1 = S[i] == 'A';
			cnt2 = 0;
		}
	}
	ans += cnt1 * cnt2;
	cout << ans << "\n";
	return 0;
}
