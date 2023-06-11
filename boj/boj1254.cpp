#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	string T = S;
	reverse(T.begin(), T.end());
	int ans{};
	for (int i = 0; i < S.size(); ++i) {
		string R = S + T.substr(S.size() - i);
		string U = R;
		reverse(U.begin(), U.end());
		if (R == U) {
			ans = S.size() + i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
