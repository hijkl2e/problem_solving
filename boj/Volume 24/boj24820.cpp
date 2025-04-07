#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	cin >> S;
	set<char> puz;
	for (char c : S) {
		puz.insert(c);
	}
	char ctr = S[0];
	int N{};
	cin >> N;
	while (N--) {
		cin >> S;
		bool yes = false;
		for (char c : S) {
			if (puz.find(c) == puz.end()) {
				yes = false;
				break;
			} else if (c == ctr) {
				yes = true;
			}
		}
		yes &= S.size() >= 4;
		if (yes) {
			cout << S << "\n";
		}
	}
	return 0;
}
