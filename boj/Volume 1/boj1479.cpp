#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

bool dp[16][2501][201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<string> A(4);
	for (int i = 0; i < 4; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> B(4);
	for (int i = 0; i < 4; ++i) {
		int p = -1;
		while ((p = S.find(A[i], p + 1)) != -1) {
			dp[1 << i][p][A[i].size()] = true;
			B[i].push_back(p);
		}
	}
	vector<int> minl(16);
	vector<int> maxl(16);
	for (int i = 1; i < 16; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (i & (1 << j)) {
				minl[i] = max<int>(minl[i], A[j].size());
				maxl[i] += A[j].size();
			}
		}
	}
	for (int i = 1; i < 16; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (i & (1 << j)) {
				continue;
			}
			for (int x : B[j]) {
				for (int k = x; k < x + A[j].size(); ++k) {
					for (int l = minl[i]; l <= maxl[i]; ++l) {
						if (dp[i][k][l]) {
							dp[i | (1 << j)][x][max<int>(A[j].size(), k - x + l)] = true;
						}
					}
				}
			}
		}
	}
	vector<int> C(16, INF);
	vector<vector<int>> D(16, vector<int>(S.size(), -INF));
	C[0] = 0;
	fill(D[0].begin(), D[0].end(), 0);
	for (int i = 0; i < 16; ++i) {
		for (int j = 1; j < 16; ++j) {
			if (i & j) {
				continue;
			}
			int z = i ? -INF : 0;
			for (int k = 0; k < S.size(); ++k) {
				for (int l = minl[j]; l <= maxl[j]; ++l) {
					if (dp[j][k][l]) {
						C[i | j] = min(C[i | j], C[i] + l);
						D[i | j][k + l - 1] = max(D[i | j][k + l - 1], z + l);
					}
				}
				z = max(z, D[i][k]);
			}
		}
	}
	int ans_x = C[15], ans_y = *max_element(D[15].begin(), D[15].end());
	cout << ans_x << " " << ans_y << "\n";
	return 0;
}
