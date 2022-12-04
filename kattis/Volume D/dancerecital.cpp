#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> B(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			int cnt{};
			for (int k = 0, l = 0; k < A[i].size() && l < A[j].size();) {
				if (A[i][k] < A[j][l]) {
					++k;
				} else if (A[i][k] > A[j][l]) {
					++l;
				} else {
					++k, ++l;
					++cnt;
				}
			}
			B[i][j] = B[j][i] = cnt;
		}
	}
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		C[i] = i;
	}
	int ans = 1e9;
	do {
		int cnt{};
		for (int i = 1; i < N; ++i) {
			cnt += B[C[i - 1]][C[i]];
		}
		ans = min(ans, cnt);
	} while (next_permutation(C.begin(), C.end()));
	cout << ans << "\n";
	return 0;
}
