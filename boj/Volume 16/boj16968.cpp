#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int ans = 1;
	for (int i = 0; i < S.size(); ++i) {
		ans *= (S[i] == 'c' ? 26 : 10) - (i && S[i - 1] == S[i] ? 1 : 0);
	}
	cout << ans << "\n";
	return 0;
}
