#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	reverse(S.begin(), S.end());
	int ans{};
	for (int i = 1;; ++i) {
		for (char c : to_string(i)) {
			if (S.size() && S.back() == c) {
				S.pop_back();
			}
		}
		if (S.empty()) {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
