#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		int ans{}, cnt{};
		for (char c : S) {
			if (c == 'O') {
				ans += ++cnt;
			} else {
				cnt = 0;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
