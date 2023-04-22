#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
using iii = tuple<int, int, int>;

ii solve(vector<iii> &A) {
	ii ret;
	vector<vector<int>> B(6, vector<int>(4));
	int cntr{};
	for (auto &[t, x, z] : A) {
		int y = 1;
		while (y < 5 && B[y + 1][x] == 0 && (t < 3 || B[y + 1][x + 1] == 0)) {
			++y;
		}
		B[y][x] = B[y - (t == 2)][x] = B[y][x + (t == 3)] = ++cntr;
		while (true) {
			for (int i = 5; i > 1; --i) {
				while (count(B[i].begin(), B[i].end(), 0) == 0) {
					fill(B[i].begin(), B[i].end(), 0);
					rotate(B.begin(), B.begin() + i, B.begin() + i + 1);
					++ret.first;
				}
			}
			if (count(B[1].begin(), B[1].end(), 0) == 4) {
				break;
			}
			while (count(B[1].begin(), B[1].end(), 0) < 4) {
				rotate(B.begin(), B.end() - 1, B.end());
				fill(B[0].begin(), B[0].end(), 0);
			}
		}
	}
	for (int i = 2; i < 6; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (B[i][j]) {
				++ret.second;
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<iii> A(N);
	for (auto &[t, x, y] : A) {
		cin >> t >> x >> y;
	}
	ii res1 = solve(A);
	for (auto &[t, x, y] : A) {
		if (t & 2) {
			t ^= 1;
		}
		swap(x, y);
	}
	ii res2 = solve(A);
	cout << res1.first + res2.first << "\n";
	cout << res1.second + res2.second << "\n";
	return 0;
}
