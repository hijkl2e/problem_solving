#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cin.ignore();
		string S;
		getline(cin, S);
		int cnt = 1;
		for (int i = 0; i < S.size() - 1; ++i) {
			if (S[i] == S[i + 1]) {
				continue;
			}
			++cnt;
		}
		int ans = max(cnt - 2 + (S[0] - '0'), 0);
		cout << ans << "\n";
	}
	return 0;
}
