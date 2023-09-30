#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	S = "A" + S;
	int ans{};
	for (int i = 1; i < S.size(); ++i) {
		int d = abs(S[i] - S[i - 1]);
		ans += min(d, 26 - d);
	}
	cout << ans << "\n";
	return 0;
}
