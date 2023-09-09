#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int X{}, N{}, M{};
	cin >> X >> N >> M;
	vector<int> A(2 * N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		A[N + i] = A[i];
	}
	vector<int> B(2 * M);
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
		B[M + i] = B[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	partial_sum(B.begin(), B.end(), B.begin());
	vector<int> C(2000001);
	vector<int> D(2000001);
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			++C[A[N + i] - A[N + i - j]];
		}
	}
	++C[A[N - 1]], ++C[0];
	for (int i = 0; i < M; ++i) {
		for (int j = 1; j < M; ++j) {
			++D[B[M + i] - B[M + i - j]];
		}
	}
	++D[B[M - 1]], ++D[0];
	int ans{};
	for (int i = 0; i <= X; ++i) {
		ans += C[i] * D[X - i];
	}
	cout << ans << "\n";
	return 0;
}
