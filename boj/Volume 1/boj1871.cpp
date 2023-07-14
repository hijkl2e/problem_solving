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
		for (int i = 0; i < 3; ++i) {
			x = 26 * x + S[i] - 'A';
		}
		int y = stoi(S.substr(4));
		cout << (abs(x - y) > 100 ? "not " : "") << "nice\n";
	}
	return 0;
}
