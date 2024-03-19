#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> key{"qwertyuiop", "asdfghjkl", "zxcvbnm"};
	vector<int> x(128);
	vector<int> y(128);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < key[i].size(); ++j) {
			x[key[i][j]] = i;
			y[key[i][j]] = j;
		}
	}
	char l{}, r{};
	cin >> l >> r;
	cin.ignore();
	string S;
	getline(cin, S);
	int lx{}, ly{}, rx{}, ry{};
	lx = x[l], ly = y[l], rx = x[r], ry = y[r];
	int ans = S.size();
	for (char c : S) {
		if (y[c] > 4 || c == 'b') {
			ans += abs(x[c] - rx) + abs(y[c] - ry);
			rx = x[c], ry = y[c];
		} else {
			ans += abs(x[c] - lx) + abs(y[c] - ly);
			lx = x[c], ly = y[c];
		}
	}
	cout << ans << "\n";
	return 0;
}
