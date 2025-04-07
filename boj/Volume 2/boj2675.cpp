#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int R{};
		string S;
		cin >> R >> S;
		for (char c : S) {
			for (int i = 0; i < R; ++i) {
				cout << c;
			}
		}
		cout << "\n";
	}
	return 0;
}
