#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> dp{0, 0, 2, 2, 1, 4, 3, 3, 1, 4, 2};
	int T = 3;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		cin.ignore();
		vector<string> A(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, A[i]);
		}
		if (N % 2) {
			A.push_back(string(M, '#'));
		}
		int ans{};
		for (int i = 0; i < N; i += 2) {
			int cnt{};
			for (int j = 0; j < M; ++j) {
				if (A[i][j] == '.' && A[i + 1][j] == '.') {
					++cnt;
				} else {
					ans ^= dp[cnt] ^ (A[i][j] == '.' || A[i + 1][j] == '.');
					cnt = 0;
				}
			}
			if (cnt) {
				ans ^= dp[cnt];
			}
		}
		cout << (ans ? "Y" : "M") << "\n";
	}
	return 0;
}
