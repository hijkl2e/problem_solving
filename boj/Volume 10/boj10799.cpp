#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int cnt{}, ans{};
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] == '(') {
			++cnt;
		} else {
			--cnt;
			ans += S[i - 1] == '(' ? cnt : 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
