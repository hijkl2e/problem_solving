#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int prev{}, ans{};
	for (int i = 0; i < S.size(); ++i) {
		if (isupper(S[i])) {
			ans += (4 - (i - prev) % 4) % 4;
			prev = i;
		}
	}
	cout << ans << "\n";
	return 0;
}
