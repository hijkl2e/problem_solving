#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(10, vector<int>(10));
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> B(12, vector<int>(12));
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 12; ++j) {
			cin >> B[i][j];
		}
	}
	vector<vector<int>> C(6, vector<int>(60));
	while (N--) {
		int x{};
		string s;
		cin >> x >> s;
		++C[x][6 * (s[0] - '0') + (s[1] - 'A') / 2];
	}
	vector<vector<int>> D(60);
	for (int i = 0; i < 60; ++i) {
		for (int j = 5; j > 0; --j) {
			while (C[j][i] && D[i].size() < 3) {
				D[i].insert(D[i].begin(), j);
				--C[j][i];
			}
		}
	}
	int ans{};
	for (int i = 0; i < 60; ++i) {
		if (D[i].empty()) {
			continue;
		}
		int x1 = i / 6;
		int y1 = i % 6 * 2 + x1 % 2;
		int z1 = D[i].back();
		D[i].pop_back();
		for (int j = i; j < 60; ++j) {
			if (D[j].empty()) {
				continue;
			}
			int x2 = j / 6;
			int y2 = j % 6 * 2 + x2 % 2;
			int z2 = D[j].back();
			D[j].pop_back();
			for (int k = j; k < 60; ++k) {
				if (D[k].empty()) {
					continue;
				}
				int x3 = k / 6;
				int y3 = k % 6 * 2 + x3 % 2;
				int z3 = D[k].back();
				int res = z1 + z2 + z3;
				res += A[x1][x2] + A[x2][x3] + A[x3][x1];
				res += B[y1][y2] + B[y2][y3] + B[y3][y1];
				ans = max(ans, res);
			}
			D[j].push_back(z2);
		}
		D[i].push_back(z1);
	}
	cout << ans << "\n";
	return 0;
}
