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
		if (N == 1 || N == 3) {
			cout << "-1\n";
			continue;
		} else if (N == 2) {
			cout << (S == "01" || S == "10" ? 0 : 1) << "\n";
			continue;
		}
		int ans = 2;
		int i{};
		for (; i < N / 2; ++i) {
			if (S[i] == S[N - i - 1]) {
				ans = i == 0 && S[1] == S[N - 2] ? 2 : 1;
				break;
			} else if (i && S[i] != S[i - 1]) {
				ans = 0;
				break;
			}
		}
		if (i == N / 2 && N % 2 == 0) {
			ans = 0;
		}
		cout << ans << "\n";
	}
	return 0;
}
