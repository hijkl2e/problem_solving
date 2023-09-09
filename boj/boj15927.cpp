#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	if (count(S.begin(), S.end(), S[0]) == S.size()) {
		cout << "-1\n";
		return 0;
	}
	string T = S;
	reverse(T.begin(), T.end());
	int ans = S.size() - (S == T);
	cout << ans << "\n";
	return 0;
}
