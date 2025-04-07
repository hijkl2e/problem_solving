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
		int cnt = count(S.begin(), S.end(), 'L');
		int ans{};
		if (cnt == 0 || cnt == N) {
			ans = -1;
		} else {
			for (int i = 0; i < N - 1; ++i) {
				if (S[i] == 'L' && S[i + 1] == 'R') {
					ans = i + 1;
					break;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
