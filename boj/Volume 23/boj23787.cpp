#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int cnt{}, maxv{};
	for (char c : S) {
		if (c == '0') {
			++cnt;
		} else {
			maxv = max(maxv, cnt);
			cnt = 0;
		}
	}
	maxv = max(maxv, cnt);
	cout << (maxv + 1) / 2 << "\n";
	return 0;
}
