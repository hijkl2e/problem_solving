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
		bool yes = true;
		for (int i = 0; i < N; ++i) {
			int cnt{};
			for (int j = 0; j < M; ++j) {
				if (A[i][j] != '.') {
					++cnt;
				}
			}
			yes &= cnt % 2 == 0;
		}
		for (int j = 0; j < M; ++j) {
			int cnt{};
			for (int i = 0; i < N; ++i) {
				if (A[i][j] != '.') {
					++cnt;
				}
			}
			yes &= cnt % 2 == 0;
		}
		if (!yes) {
			cout << "-1\n";
			continue;
		}
		for (int i = 0; i < N; ++i) {
			char c = 'B';
			for (int j = 0; j < M; ++j) {
				if (A[i][j] == 'U') {
					A[i][j] = c;
					c = c == 'B' ? 'W' : 'B';
					A[i + 1][j] = c;
				}
			}
		}
		for (int j = 0; j < M; ++j) {
			char c = 'B';
			for (int i = 0; i < N; ++i) {
				if (A[i][j] == 'L') {
					A[i][j] = c;
					c = c == 'B' ? 'W' : 'B';
					A[i][j + 1] = c;
				}
			}
		}
		for (auto &s : A) {
			cout << s << "\n";
		}
	}
	return 0;
}
