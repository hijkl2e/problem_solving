#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int cnt{}, minv{};
	for (char c : S) {
		if (c == '(') {
			++cnt;
		} else {
			minv = min(minv, --cnt);
		}
	}
	int ans = cnt - 2 * minv;
	cout << ans << "\n";
	return 0;
}
