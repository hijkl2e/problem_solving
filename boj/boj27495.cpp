#include <bits/stdc++.h>

using namespace std;

using sv = pair<string, vector<string>>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<string>> A(9, vector<string>(9));
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> A[i][j];
		}
	}
	vector<sv> B(9);
	for (int i = 0; i < 9; ++i) {
		int r = i / 3 * 3;
		int c = i % 3 * 3;
		B[i].first = A[r + 1][c + 1];
		auto &v = B[i].second;
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				if (j == 1 && k == 1) {
					continue;
				}
				v.push_back(A[r + j][c + k]);
			}
		}
		sort(v.begin(), v.end());
	}
	B.erase(B.begin() + 4);
	sort(B.begin(), B.end());
	for (int i = 0; i < 8; ++i) {
		cout << "#" << i + 1 << ". " << B[i].first << "\n";
		for (int j = 0; j < 8; ++j) {
			cout << "#" << i + 1 << "-" << j + 1 << ". " << B[i].second[j] << "\n";
		}
	}
	return 0;
}
