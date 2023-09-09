#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	sort(S.begin(), S.end());
	int ans{};
	do {
		bool flag = true;
		for (int i = 1; i < S.size(); ++i) {
			if (S[i] == S[i - 1]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			++ans;
		}
	} while (next_permutation(S.begin(), S.end()));
	cout << ans << "\n";
	return 0;
}
