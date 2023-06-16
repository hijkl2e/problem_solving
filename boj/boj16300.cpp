#include <bits/stdc++.h>

using namespace std;

map<char, int> solve(string &s) {
	map<char, int> ret;
	char prev{};
	int cnt{};
	for (char c : s) {
		if (isalpha(c)) {
			if (prev) {
				ret[prev] += max(cnt, 1);
			}
			prev = c;
			cnt = 0;
		} else {
			cnt = 10 * cnt + c - '0';
		}
	}
	ret[prev] += max(cnt, 1);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	int K{};
	cin >> s1 >> K >> s2;
	map<char, int> f1 = solve(s1);
	map<char, int> f2 = solve(s2);
	for (auto &p : f1) {
		p.second *= K;
	}
	int ans = 1e9;
	for (auto &p : f2) {
		ans = min(ans, f1[p.first] / p.second);
	}
	cout << ans << "\n";
	return 0;
}
