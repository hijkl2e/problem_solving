#include <bits/stdc++.h>

using namespace std;

bool solve(string &s, int p) {
	int cnt{};
	for (int i = 0; p + i < s.size(); ++i) {
		if (s[i] != s[p + i]) {
			++cnt;
		}
	}
	return cnt == 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	bool yes{};
	for (int i = 0; i < N; ++i) {
		if (solve(S, i)) {
			yes = true;
			break;
		}
	}
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
