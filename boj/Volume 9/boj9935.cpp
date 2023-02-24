#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S, T;
	getline(cin, S);
	getline(cin, T);
	string ans;
	for (char c : S) {
		ans += c;
		if (ans.size() >= T.size() && ans.substr(ans.size() - T.size()) == T) {
			ans.erase(ans.end() - T.size(), ans.end());
		}
	}
	if (ans.size()) {
		cout << ans << "\n";
	} else {
		cout << "FRULA\n";
	}
	return 0;
}
