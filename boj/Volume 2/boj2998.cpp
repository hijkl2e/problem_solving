#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	while (S.size() % 3) {
		S.insert(S.begin(), '0');
	}
	for (int i = 0; i < S.size(); i += 3) {
		int x{};
		for (int j = 0; j < 3; ++j) {
			x = 2 * x + S[i + j] - '0';
		}
		cout << x;
	}
	cout << "\n";
	return 0;
}
