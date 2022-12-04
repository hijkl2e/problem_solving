#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S)) {
		char c = S[0];
		int cnt = 1;
		for (int i = 1; i < S.size(); ++i) {
			if (c == S[i]) {
				++cnt;
			} else {
				cout << cnt << c;
				c = S[i];
				cnt = 1;
			}
		}
		cout << cnt << c << "\n";
	}
	return 0;
}
