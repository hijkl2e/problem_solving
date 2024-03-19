#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	while (N--) {
		string S;
		getline(cin, S);
		int ans{};
		for (char c : S) {
			if (isalpha(c)) {
				ans += c - 'A' + 1;
			}
		}
		if (ans == 100) {
			cout << "PERFECT LIFE\n";
		} else {
			cout << ans << "\n";
		}
	}
	return 0;
}
