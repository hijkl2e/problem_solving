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
		int x = -1;
		for (int i = 0; i < S.size() - i - 1; ++i) {
			if (S[i] != S[S.size() - i - 1]) {
				x = i;
				break;
			}
		}
		if (x == -1) {
			cout << "1 " << S.size() / 2 + 1 << "\n";
		} else {
			cout << "0 " << x + 1 << "\n";
		}
	}
	return 0;
}
