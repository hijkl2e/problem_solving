#include <bits/stdc++.h>

using namespace std;

int K, ans;
vector<int> L(5);
vector<vector<int>> A(5);
vector<int> M(3);
vector<vector<int>> C(3);
vector<vector<int>> V[3];
vector<int> B(5);

void solve(int step, int T) {
	if (step == 4) {
		int res{};
		for (int i = 0; i < 5; ++i) {
			res += A[i][min(B[i], L[i])];
		}
		ans = max(ans, res);
		return;
	} else if (step == 3) {
		if (T >= K) {
			for (int i = 0; i < 5; ++i) {
				if (!B[i]) {
					continue;
				}
				--B[i];
				for (int j = 0; j < 5; ++j) {
					if (i == j) {
						continue;
					}
					++B[j];
					solve(step + 1, T - K);
					--B[j];
				}
				++B[i];
			}
		} else {
			solve(step + 1, T);
		}
		return;
	}
	for (int i = 0; i < M[step]; ++i) {
		if (T < C[step][i]) {
			continue;
		}
		for (int j = 0; j < 5; ++j) {
			B[j] += V[step][i][j];
		}
		solve(step + 1, T - C[step][i]);
		for (int j = 0; j < 5; ++j) {
			B[j] -= V[step][i][j];
		}
	}
	solve(step + 1, T);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T >> K;
	for (int i = 0; i < 5; ++i) {
		cin >> L[i];
		A[i].resize(L[i] + 1);
		for (int j = 1; j <= L[i]; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < 3; ++i) {
		cin >> M[i];
		C[i].resize(M[i]);
		for (int j = 0; j < M[i]; ++j) {
			cin >> C[i][j];
		}
		V[i].resize(M[i]);
		for (int j = 0; j < M[i]; ++j) {
			V[i][j].resize(5);
			for (int k = 0; k < 5; ++k) {
				cin >> V[i][j][k];
			}
		}
	}
	solve(0, T);
	cout << ans << "\n";
	return 0;
}
