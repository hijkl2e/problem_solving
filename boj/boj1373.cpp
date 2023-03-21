#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	if (S == "0") {
		cout << "0\n";
		return 0;
	}
	while (S.size() % 3) {
		S = "0" + S;
	}
	for (int i = 0; i < S.size(); i += 3) {
		int x = 4 * S[i] + 2 * S[i + 1] + S[i + 2] - 7 * '0';
		cout << x;
	}
	cout << "\n";
	return 0;
}
