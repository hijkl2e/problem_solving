#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	cout << (S[0] + S[4] - '0' == S[8] ? "YES" : "NO") << "\n";
	return 0;
}
