#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<vector<int>> B(N / 2 + 1, vector<int>(M / 2 + 1));
	vector<int> C(4);
	for (int i = 0; i < N / 2; ++i) {
		for (int j = 0; j < M / 2; ++j) {
			for (int k = 0; k < 4; ++k) {
				C[k] = A[k / 2 ? N - i - 1 : i][k % 2 ? M - j - 1 : j] - '0';
			}
			int cnt = accumulate(C.begin(), C.end(), 0);
			if (cnt % 4 == 0) {
				continue;
			} else if (cnt % 2) {
				cout << "-1\n";
				return 0;
			}
			for (int k = 1; k < 4; ++k) {
				if (C[k] == C[0]) {
					B[i][j] = k;
					break;
				}
			}
		}
	}
	vector<vector<int>> D(N / 2 + 1, vector<int>(M / 2 + 1));
	int ans{};
	for (int i = 0; i < N / 2; ++i) {
		for (int j = 0; j < M / 2; ++j) {
			B[i][j] ^= D[i][j];
			if (B[i][j]) {
				if (i + K > N / 2 || j + K > M / 2) {
					cout << "-1\n";
					return 0;
				}
				for (int k = 0; k < 4; ++k) {
					D[i + (k / 2 ? K : 0)][j + (k % 2 ? K : 0)] ^= B[i][j];
				}
				++ans;
			}
			for (int k = 1; k < 4; ++k) {
				D[i + k / 2][j + k % 2] ^= D[i][j];
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
