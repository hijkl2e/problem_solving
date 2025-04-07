#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> A;

int solve(int x, int t) {
	int ret{}, cnt = 1;
	if (t == 1) {
		for (int i = 1; i < N; ++i) {
			if (A[x][i - 1] == A[x][i]) {
				++cnt;
			} else {
				ret = max(ret, cnt);
				cnt = 1;
			}
		}
	} else {
		for (int i = 1; i < N; ++i) {
			if (A[i - 1][x] == A[i][x]) {
				++cnt;
			} else {
				ret = max(ret, cnt);
				cnt = 1;
			}
		}
	}
	ret = max(ret, cnt);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	cin.ignore();
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans = max(ans, solve(i, 1));
		ans = max(ans, solve(i, 2));
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - 1; ++j) {
			if (A[i][j] != A[i][j + 1]) {
				swap(A[i][j], A[i][j + 1]);
				ans = max(ans, solve(i, 1));
				ans = max(ans, solve(j, 2));
				ans = max(ans, solve(j + 1, 2));
				swap(A[i][j], A[i][j + 1]);
			}
			if (A[j][i] != A[j + 1][i]) {
				swap(A[j][i], A[j + 1][i]);
				ans = max(ans, solve(i, 2));
				ans = max(ans, solve(j, 1));
				ans = max(ans, solve(j + 1, 1));
				swap(A[j][i], A[j + 1][i]);
			}
		}
	}
	return 0;
}
