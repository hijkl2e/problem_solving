#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		vector<int> B(A[i].begin(), A[i].end());
		sort(B.begin(), B.end());
		B.resize(unique(B.begin(), B.end()) - B.begin());
		for (int j = 0; j < M; ++j) {
			A[i][j] = lower_bound(B.begin(), B.end(), A[i][j]) - B.begin();
		}
	}
	sort(A.begin(), A.end());
	int ans{};
	for (int i = 0, j = 1; i < N; i = j++) {
		while (j < N && A[i] == A[j]) {
			++j;
		}
		ans += (j - i) * (j - i - 1) / 2;
	}
	cout << ans << "\n";
	return 0;
}
