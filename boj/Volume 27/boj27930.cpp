#include <bits/stdc++.h>

using namespace std;

int solve(const string &s1, const string &s2) {
	for (int i = 0, j = 0; i < s1.size(); ++i) {
		if (s1[i] == s2[j] && ++j == s2.size()) {
			return i;
		}
	}
	return s1.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int x = solve(S, "YONSEI");
	int y = solve(S, "KOREA");
	string ans = x < y ? "YONSEI" : "KOREA";
	cout << ans << "\n";
	return 0;
}
