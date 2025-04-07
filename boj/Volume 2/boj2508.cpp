#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		cin.ignore();
		vector<string> A(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, A[i]);
		}
		int ans{};
		for (int i = 0; i < N; ++i) {
			for (int j = 1; j < M - 1; ++j) {
				if (A[i][j] == 'o' && A[i][j - 1] == '>' && A[i][j + 1] == '<') {
					++ans;
				}
			}
		}
		for (int j = 0; j < M; ++j) {
			for (int i = 1; i < N - 1; ++i) {
				if (A[i][j] == 'o' && A[i - 1][j] == 'v' && A[i + 1][j] == '^') {
					++ans;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
