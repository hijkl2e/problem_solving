#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int ans{};
	for (int i = 0; i < S.size(); ++i) {
		ans += i && S[i - 1] == S[i] ? 5 : 10;
	}
	cout << ans << "\n";
	return 0;
}
