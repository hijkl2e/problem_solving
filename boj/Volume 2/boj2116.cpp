#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &v, int x, int y) {
	int ret{};
	for (int i = 0; i < 6; ++i) {
		if (i == x || i == y) {
			continue;
		}
		ret = max(ret, v[i]);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(6));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 6; ++j) {
			cin >> A[i][j];
		}
		rotate(A[i].begin() + 3, A[i].end() - 1, A[i].end());
	}
	int ans{};
	for (int i = 1; i < 7; ++i) {
		int p1 = find(A[0].begin(), A[0].end(), i) - A[0].begin();
		int p2 = (p1 + 3) % 6;
		int sum = solve(A[0], p1, p2);
		for (int j = 1; j < N; ++j) {
			p1 = find(A[j].begin(), A[j].end(), A[j - 1][p2]) - A[j].begin();
			p2 = (p1 + 3) % 6;
			sum += solve(A[j], p1, p2);
		}
		ans = max(ans, sum);
	}
	cout << ans << "\n";
	return 0;
}
