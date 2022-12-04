#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int TC{};
	cin >> TC;
	cin.ignore();
	for (int tc = 1; tc <= TC; ++tc) {
		string S, T;
		getline(cin, S);
		getline(cin, T);
		cout << "Case " << tc << ": ";
		int s1{}, t1{};
		for (int i = 0; i < S.size(); ++i) {
			if (S[i] == T[i]) {
				continue;
			}
			if (S[i] == '1') {
				++s1;
			} else if (T[i] == '1') {
				++t1;
			}
		}
		if (s1 > t1) {
			cout << "-1\n";
			continue;
		}
		int ans = t1;
		for (int i = 0; i < S.size(); ++i) {
			if (S[i] == '?') {
				if (T[i] == '1' && s1 < t1) {
					++s1;
				} else {
					++ans;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
