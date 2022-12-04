#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S)) {
		bool free = true;
		for (char c : S) {
			free ^= __builtin_popcount(c) & 1;
		}
		free &= S.size() % 2 == 0;
		cout << (free ? "free" : "trapped") << "\n";
	}
	return 0;
}
