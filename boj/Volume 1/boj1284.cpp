#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S), S != "0") {
		int ans = S.size() + 1;
		for (char c : S) {
			ans += c == '1' ? 2 : c == '0' ? 4 : 3;
		}
		cout << ans << "\n";
	}
	return 0;
}
