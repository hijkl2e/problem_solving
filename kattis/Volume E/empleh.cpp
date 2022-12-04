#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> grid(17);
	for (int i = 0; i < 17; ++i) {
		grid[i] = i % 2 ? i / 2 % 2 ? "|:::|..." : "|...|:::" : "+---+---";
		for (int j = 0; j < 2; ++j) {
			grid[i] += grid[i];
		}
		grid[i] += grid[i][0];
	}
	string S;
	getline(cin, S);
	istringstream iss(S.substr(7));
	while (getline(iss, S, ',')) {
		if (S.size() == 2) {
			S = 'P' + S;
		}
		int x = 15 - 2 * (S[2] - '1');
		int y = 2 + 4 * (S[1] - 'a');
		grid[x][y] = S[0];
	}
	getline(cin, S);
	iss = istringstream(S.substr(7));
	while (getline(iss, S, ',')) {
		if (S.size() == 2) {
			S = 'P' + S;
		}
		int x = 15 - 2 * (S[2] - '1');
		int y = 2 + 4 * (S[1] - 'a');
		grid[x][y] = tolower(S[0]);
	}
	for (int i = 0; i < 17; ++i) {
		cout << grid[i] << "\n";
	}
	return 0;
}
