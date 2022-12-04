#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N != -1) {
		vector<vector<int>> A(N, vector<int>(N));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> A[i][j];
			}
		}
		deque<bool> chk(N);
		for (int i = 0; i < N; ++i) {
			if (chk[i]) {
				continue;
			}
			for (int j = 0; j < N; ++j) {
				if (A[i][j] == 0) {
					continue;
				}
				for (int k = j + 1; k < N; ++k) {
					if (A[i][k] && A[j][k]) {
						chk[i] = chk[j] = chk[k] = true;
					}
				}
			}
		}
		vector<int> B;
		for (int i = 0; i < N; ++i) {
			if (!chk[i]) {
				B.push_back(i);
			}
		}
		for (int i = 0; i < B.size(); ++i) {
			cout << B[i] << (i == B.size() - 1 ? "" : " ");
		}
		cout << "\n";
	}
	return 0;
}
