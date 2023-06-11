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
		deque<bool> A(26);
		for (char c : S) {
			A[c - 'A'] = true;
		}
		int ans{};
		for (int i = 0; i < 26; ++i) {
			if (!A[i]) {
				ans += i + 65;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
