#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		if (S == "^") {
			cout << "1\n";
			continue;
		}
		int ans{};
		for (int i = 0; i < S.size(); ++i) {
			if (S[i] == '^') {
				continue;
			}
			ans += (i == 0) + (i == S.size() - 1 || S[i + 1] == '_');
		}
		cout << ans << "\n";
	}
	return 0;
}
