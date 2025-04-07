#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> A{
		{0, 1, 2, 3, 8, 9, 10, 11}, {4, 5, 6, 7, 12, 13, 14, 15},
		{3, 2, 7, 6, 10, 18, 14, 19}, {1, 0, 5, 4, 8, 16, 12, 17},
		{0, 3, 6, 5, 11, 19, 13, 16}, {2, 1, 4, 7, 9, 17, 15, 18}
	};
	vector<string> B{
		"wog", "wbo", "wrb", "wgr", "yob", "ygo", "yrg", "ybr",
		"wo", "wb", "wr", "wg", "yo", "yg", "yr", "yb", "go", "bo", "br", "gr", "w"
	};
	vector<int> C{0, 8, 1, 11, 20, 9, 3, 10, 2};
	map<char, int> d2i{
		{'U', 0}, {'D', 1}, {'F', 2}, {'B', 3}, {'L', 4}, {'R', 5}
	};
	int T{};
	cin >> T;
	while (T--) {
		vector<int> D(21);
		vector<int> E(21);
		for (int i = 0; i < 21; ++i) {
			D[i] = i;
		}
		int N{};
		cin >> N;
		while (N--) {
			string s;
			cin >> s;
			int x = d2i[s[0]];
			int y = s[1] == '+' ? 1 : 3;
			while (y--) {
				for (int i = 0; i < 8; ++i) {
					int &z = E[D[A[x][i]]];
					z = (z + (i < 4 ? x < 2 ? 0 : (i % 2 + 1) : (x > 3))) % (i < 4 ? 3 : 2);
				}
				for (int k = 0; k < 8; k += 4) {
					int z = D[A[x][k + 3]];
					for (int i = 3; i > 0; --i) {
						D[A[x][k + i]] = D[A[x][k + i - 1]];
					}
					D[A[x][k]] = z;
				}
			}
		}
		for (int i = 0; i < 9; ++i) {
			int x = D[C[i]];
			cout << B[x][E[x]] << (i % 3 == 2 ? "\n" : "");
		}
	}
	return 0;
}
