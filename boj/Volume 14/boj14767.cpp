#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<ll>> A(N + 1, vector<ll>(M + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<ll>> B(N + 1, vector<ll>(M + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			B[i][j] = max(B[i - 1][j], B[i][j - 1]) + A[i][j];
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << B[i][M] << (i == N ? "\n" : " ");
	}
	return 0;
}
