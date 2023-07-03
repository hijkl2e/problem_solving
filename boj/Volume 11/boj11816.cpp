#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int ans{};
	if (S[0] == '0') {
		if (S.size() > 1 && S[1] == 'x') {
			ans = stoi(S.substr(2), nullptr, 16);
		} else {
			ans = stoi(S, nullptr, 8);
		}
	} else {
		ans = stoi(S);
	}
	cout << ans << "\n";
	return 0;
}
