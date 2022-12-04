#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int ans = S[0] == 'U' ? S[1] == 'U' ? 0 : 2 : 1;
	ans += 2 * count(S.begin() + 2, S.end(), 'D');
	cout << ans << "\n";
	ans = S[0] == 'D' ? S[1] == 'D' ? 0 : 2 : 1;
	ans += 2 * count(S.begin() + 2, S.end(), 'U');
	cout << ans << "\n";
	ans = 0;
	for (int i = 0; i < S.size() - 1; ++i) {
		if (S[i] != S[i + 1]) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
