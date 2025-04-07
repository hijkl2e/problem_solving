#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
	vector<deque<bool>> B(N, deque<bool>(M));
	for (int i = 0; i < N; ++i) {
		int k = max_element(A[i].begin(), A[i].end()) - A[i].begin();
		B[i][k] = true;
	}
	for (int j = 0; j < M; ++j) {
		int maxi{};
		for (int i = 0; i < N; ++i) {
			if (A[maxi][j] < A[i][j]) {
				maxi = i;
			}
		}
		B[maxi][j] = true;
	}
	ll ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!B[i][j]) {
				ans += A[i][j];
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
