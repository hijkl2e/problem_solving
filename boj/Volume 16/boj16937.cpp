#include <bits/stdc++.h>

using namespace std;

bool solve(int N, int M, int r1, int c1, int r2, int c2) {
	return (r1 + r2 <= N && max(c1, c2) <= M) || (c1 + c2 <= M && max(r1, r2) <= N);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<int> A(K);
	vector<int> B(K);
	for (int i = 0; i < K; ++i) {
		cin >> A[i] >> B[i];
	}
	int ans{};
	for (int i = 0; i < K; ++i) {
		for (int j = i + 1; j < K; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (solve(N, M, A[i], B[i], A[j], B[j])) {
					ans = max(ans, A[i] * B[i] + A[j] * B[j]);
				}
				swap(A[j], B[j]);
				if (k % 2) {
					swap(A[i], B[i]);
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
