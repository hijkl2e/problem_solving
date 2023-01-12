#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	set<string> S;
	string s;
	while (getline(cin, s) && s != "#") {
		S.insert(s);
	}
	while (getline(cin, s) && s != "#") {
		string msg = s;
		while (msg.back() != '|') {
			getline(cin, s);
			msg += s;
		}
		int ans{};
		for (int i = 0, j = 0; i < msg.size(); ++i) {
			for (int k = 1; k < 11 && i - k + 1 >= j; ++k) {
				if (S.find(msg.substr(i - k + 1, k)) != S.end()) {
					j = i + 1;
					++ans;
					break;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
