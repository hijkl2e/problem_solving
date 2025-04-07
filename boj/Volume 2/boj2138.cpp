#include <bits/stdc++.h>

using namespace std;

int solve(string s1, string s2, bool f) {
	int ret{};
	if (f) {
		s1[0] ^= 1, s1[1] ^= 1;
		++ret;
	}
	for (int i = 1; i < s1.size(); ++i) {
		if (s1[i - 1] == s2[i - 1]) {
			continue;
		}
		for (int j = -1; j < 2; ++j) {
			if (0 <= i + j && i + j < s1.size()) {
				s1[i + j] ^= 1;
			}
		}
		++ret;
	}
	return s1 == s2 ? ret : -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int ans = solve(s1, s2, false);
	if (ans == -1) {
		ans = solve(s1, s2, true);
	}
	cout << ans << "\n";
	return 0;
}
