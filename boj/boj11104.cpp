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
		int x{};
		for (char c : S) {
			x = 2 * x + c - '0';
		}
		cout << x << "\n";
	}
	return 0;
}
