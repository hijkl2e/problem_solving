#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	cin.ignore();
	string S;
	getline(cin, S);
	int ans{};
	for (int i = 0; i < N; ++i) {
		if (S[i] != 'P') {
			continue;
		}
		for (int j = max(i - K, 0); j <= i + K && j < N; ++j) {
			if (S[j] == 'H') {
				S[j] = 'X';
				++ans;
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
