#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, int> freq;
	for (int i = 0; i < 5; ++i) {
		string s;
		cin >> s;
		++freq[s[0]];
	}
	int ans{};
	for (auto &p : freq) {
		ans = max(ans, p.second);
	}
	cout << ans << "\n";
	return 0;
}
