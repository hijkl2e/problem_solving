#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{}, H{};
	cin >> L >> H;
	int ans{};
	for (int i = L; i <= H; ++i) {
		string s = to_string(i);
		sort(s.begin(), s.end());
		if (unique(s.begin(), s.end()) != s.end()) {
			continue;
		}
		bool yes = true;
		for (char c : s) {
			if (c == '0' || i % (c - '0')) {
				yes = false;
				break;
			}
		}
		if (yes) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
