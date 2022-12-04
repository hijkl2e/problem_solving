#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int now = -1;
	string S;
	while (getline(cin, S)) {
		if (S.empty()) {
			cout << "\n";
			now = -1;
			continue;
		}
		if (now == -1) {
			now = S.size();
		}
		int cnt = count(S.begin(), S.end(), '*');
		fill(S.begin(), S.end(), '.');
		while (cnt--) {
			S[--now] = '*';
		}
		cout << S << "\n";
	}
	return 0;
}
