#include <bits/stdc++.h>
#include "MM.h"

using namespace std;

int solve(vector<int> &A, vector<int> &B) {
	static vector<int> C(7);
	static vector<int> D(7);
	fill(C.begin(), C.end(), 0);
	fill(D.begin(), D.end(), 0);
	int r{}, w{};
	for (int i = 0; i < 4; ++i) {
		if (A[i] == B[i]) {
			++r;
		} else {
			++C[A[i]];
			++D[B[i]];
		}
	}
	for (int i = 1; i < 7; ++i) {
		w += min(C[i], D[i]);
	}
	return 5 * r + w;
}

vector<vector<int>> A(1296, vector<int>(4));
vector<vector<int>> B(10648);

void init(int T, int K) {
	for (int i = 0; i < 1296; ++i) {
		int k = i;
		for (int j = 0; j < 4; ++j) {
			A[i][j] = k % 6 + 1;
			k /= 6;
		}
	}
	B[10647] = {1, 1, 2, 2};
}

void game() {
	int z = 10647;
	vector<vector<int>> C = A;
	while (true) {
		if (C.size() == 1) {
			guess(C[0]);
			return;
		}
		if (B[z].empty()) {
			int minv = 1e9, mini{};
			vector<int> D(21);
			for (int i = 0, j = 0; i < A.size(); ++i) {
				fill(D.begin(), D.end(), 0);
				for (int j = 0; j < C.size(); ++j) {
					++D[solve(A[i], C[j])];
				}
				int maxv = *max_element(D.begin(), D.end());
				if (minv > maxv || (minv == maxv && ++j < 5)) {
					j = minv == maxv ? j : 0;
					minv = maxv;
					mini = i;
				}
			}
			B[z] = A[mini];
		}
		auto [x, y] = guess(B[z]);
		if (x == 4) {
			return;
		}
		vector<vector<int>> E;
		for (int i = 0; i < C.size(); ++i) {
			if (solve(B[z], C[i]) == 5 * x + y) {
				E.push_back(C[i]);
			}
		}
		z = (22 * z + 5 * x + y) % 10648;
		swap(C, E);
	}
}
