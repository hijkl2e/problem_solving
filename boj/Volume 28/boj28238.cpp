#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(5));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> A[i][j];
		}
	}
	int maxv = -1;
	vector<int> B(5);
	for (int i = 0; i < 5; ++i) {
		for (int j = i + 1; j < 5; ++j) {
			int cnt{};
			for (int k = 0; k < N; ++k) {
				if (A[k][i] && A[k][j]) {
					++cnt;
				}
			}
			if (maxv < cnt) {
				maxv = cnt;
				fill(B.begin(), B.end(), 0);
				B[i] = B[j] = 1;
			}
		}
	}
	cout << maxv << "\n";
	for (int i = 0; i < 5; ++i) {
		cout << B[i] << (i == 4 ? "\n" : " ");
	}
	return 0;
}
