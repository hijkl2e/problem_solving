#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int x = (S[1] - S[0] + 26) % 26;
	int y = (S[2] - S[1] + 26) % 26;
	string ans = x == 1 ? y == 3 ? "NLCS" : "SJA" : x == 16 ? "BHA" : "KIS";
	cout << ans << "\n";
	return 0;
}
