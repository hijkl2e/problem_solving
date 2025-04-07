#include <bits/stdc++.h>

using namespace std;

int N, L;

bool solve(vector<int> &A) {
	deque<bool> B(N);
	for (int i = 0; i < N - 1; ++i) {
		if (abs(A[i] - A[i + 1]) > 1) {
			return false;
		} else if (A[i] == A[i + 1]) {
			continue;
		}
		int s = i + 1 - (A[i] + 1 == A[i + 1] ? L : 0);
		int e = s + L;
		if (s < 0 || N < e || count(A.begin() + s, A.begin() + e, A[s]) < L
				|| accumulate(B.begin() + s, B.begin() + e, 0)) {
			return false;
		}
		fill(B.begin() + s, B.begin() + e, true);
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> L;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	int ans{};
	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < N; ++i) {
			if (solve(A[i])) {
				++ans;
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = i; j < N; ++j) {
				swap(A[i][j], A[j][i]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
