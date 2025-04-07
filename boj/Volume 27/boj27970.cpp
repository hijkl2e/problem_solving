#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int ans{};
	for (int i = 0, j = 1; i < S.size(); ++i, j = 2 * j % MOD) {
		if (S[i] == 'O') {
			ans = (ans + j) % MOD;
		}
	}
	cout << ans << "\n";
	return 0;
}
