#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
		--A[i];
	}
	vector<vector<int>> B(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> B[i][j];
		}
	}
	int ans{};
	for (int i = 1; i < M; ++i) {
		ans += B[A[i - 1]][A[i]];
	}
	cout << ans << "\n";
	return 0;
}
