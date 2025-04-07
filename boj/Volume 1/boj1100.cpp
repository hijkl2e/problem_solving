#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int ans{};
	for (int i = 0; i < 8; ++i) {
		string s;
		getline(cin, s);
		for (int j = 0; j < 8; ++j) {
			if ((i + j) % 2 == 0 && s[j] == 'F') {
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
