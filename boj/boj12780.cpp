#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S, T;
	getline(cin, S);
	getline(cin, T);
	int ans{};
	for (int i = 0; i < S.size(); ++i) {
		if (S.substr(i, T.size()) == T) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
