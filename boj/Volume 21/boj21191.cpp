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
	bool yes = true;
	for (int i = 0; i < N; ++i) {
		yes &= count(A[i].begin(), A[i].end(), 'B') == N / 2;
		int cnt{};
		for (int j = 0; j < N; ++j) {
			if (A[j][i] == 'B') {
				++cnt;
			}
		}
		yes &= cnt == N / 2;
		int maxv{};
		cnt = 1;
		for (int j = 1; j < N; ++j) {
			if (A[i][j - 1] == A[i][j]) {
				++cnt;
			} else {
				maxv = max(maxv, cnt);
				cnt = 1;
			}
		}
		maxv = max(maxv, cnt);
		cnt = 1;
		for (int j = 1; j < N; ++j) {
			if (A[j - 1][i] == A[j][i]) {
				++cnt;
			} else {
				maxv = max(maxv, cnt);
				cnt = 1;
			}
		}
		maxv = max(maxv, cnt);
		yes &= maxv < 3;
	}
	cout << yes << "\n";
	return 0;
}
