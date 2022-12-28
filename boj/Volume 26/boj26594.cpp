#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int ans = S.size();
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] != S[0]) {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
