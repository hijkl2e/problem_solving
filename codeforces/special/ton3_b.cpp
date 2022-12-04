#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
		ll cnt = count(S.begin(), S.end(), '0');
		cnt = max(cnt, N - cnt);
		ll ans = cnt * (cnt == N ? cnt : (N - cnt));
		cnt = 1;
		for (int i = 1; i < S.size(); ++i) {
			if (S[i] == S[i - 1]) {
				++cnt;
			} else {
				ans = max(ans, cnt * cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt * cnt);
		cout << ans << "\n";
	}
	return 0;
}
