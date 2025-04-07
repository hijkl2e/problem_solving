#include <bits/stdc++.h>

using namespace std;

vector<int> A;

int solve(int s, int e, int x) {
	int ret{};
	for (int i = s; i < e; ++i) {
		if (A[i] > x) {
			++ret;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	A.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N, 1);
	for (int i = 1; i < N; ++i) {
		B[i] += A[i - 1] < A[i] ? B[i - 1] : 0;
	}
	vector<int> C(N, 1);
	for (int i = N - 2; i >= 0; --i) {
		C[i] += A[i] < A[i + 1] ? C[i + 1] : 0;
	}
	int ans = K;
	for (int i = 0; i < N - K + 1; ++i) {
		int x{}, y{};
		if (i) {
			x = solve(i, i + K, A[i - 1]);
			ans = max(ans, B[i - 1] + x);
		}
		if (i + K < N) {
			y = K - solve(i, i + K, A[i + K]);
			ans = max(ans, C[i + K] + y);
		}
		if (x == K && y == K) {
			ans = max(ans, B[i - 1] + K + C[i + K]);
		}
	}
	cout << ans << "\n";
	return 0;
}
