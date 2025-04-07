#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	string ans(S.size(), 'z');
	for (int i = 1; i < S.size(); ++i) {
		for (int j = i + 1; j < S.size(); ++j) {
			reverse(S.begin(), S.begin() + i);
			reverse(S.begin() + i, S.begin() + j);
			reverse(S.begin() + j, S.end());
			ans = min(ans, S);
			reverse(S.begin(), S.begin() + i);
			reverse(S.begin() + i, S.begin() + j);
			reverse(S.begin() + j, S.end());
		}
	}
	cout << ans << "\n";
	return 0;
}
