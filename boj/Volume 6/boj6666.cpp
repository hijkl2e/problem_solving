#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> grid(17);
	for (int i = 0; i < 17; ++i) {
		getline(cin, grid[16 - i]);
	}
	vector<string> W, B;
	for (char c : {'K', 'Q', 'R', 'B', 'N', 'P'}) {
		for (int i = 1; i < 17; i += 2) {
			for (int j = 2; j < grid[i].size(); j += 4) {
				if (grid[i][j] == c) {
					ostringstream oss;
					if (c != 'P') {
						oss << c;
					}
					char d = 'a' + (j - 2) / 4;
					oss << d << i / 2 + 1;
					W.push_back(oss.str());
				}
			}
		}
	}
	for (char c : {'K', 'Q', 'R', 'B', 'N', 'P'}) {
		for (int i = 15; i > 0; i -= 2) {
			for (int j = 2; j < grid[i].size(); j += 4) {
				if (grid[i][j] == tolower(c)) {
					ostringstream oss;
					if (c != 'P') {
						oss << c;
					}
					char d = 'a' + (j - 2) / 4;
					oss << d << i / 2 + 1;
					B.push_back(oss.str());
				}
			}
		}
	}
	cout << "White: ";
	for (int i = 0; i < W.size(); ++i) {
		cout << W[i] << (i == W.size() - 1 ? "" : ",");
	}
	cout << "\nBlack: ";
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "" : ",");
	}
	cout << "\n";
	return 0;
}
