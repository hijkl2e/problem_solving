#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	char c{};
	string S;
	cin >> c >> S;
	if (c == 'E') {
		char prev = S[0];
		int cnt = 1;
		for (int i = 1; i < S.size(); ++i) {
			if (prev == S[i]) {
				++cnt;
			} else {
				cout << prev << cnt;
				prev = S[i];
				cnt = 1;
			}
		}
		cout << prev << cnt << "\n";
	} else {
		for (int i = 0; i < S.size(); i += 2) {
			for (int j = S[i + 1] - '0'; j > 0; --j) {
				cout << S[i];
			}
		}
		cout << "\n";
	}
	return 0;
}
