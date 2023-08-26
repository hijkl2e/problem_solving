#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int tc = 1;; ++tc) {
		string S;
		getline(cin, S);
		if (S[0] == '-') {
			break;
		}
		int cnt{}, minv{};
		for (char c : S) {
			cnt += c == '{' ? 1 : -1;
			minv = min(minv, cnt);
		}
		int x = (1 - minv) / 2;
		cnt += 2 * x;
		int ans = cnt / 2 + x;
		cout << tc << ". " << ans << "\n";
	}
	return 0;
}
