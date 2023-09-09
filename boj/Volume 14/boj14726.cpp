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
		int sum{};
		for (int i = 0; i < S.size(); ++i) {
			int x = (i % 2 ? 1 : 2) * (S[i] - '0');
			sum += x / 10 + x % 10;
		}
		cout << (sum % 10 == 0 ? "T" : "F") << "\n";
	}
	return 0;
}
