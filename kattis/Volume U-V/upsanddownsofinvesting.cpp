#include <bits/stdc++.h>

using namespace std;

int solve(int S, vector<int> &A, int N) {
	vector<int> B(S, 1);
	vector<int> C(S, 1);
	for (int i = 1; i < S; ++i) {
		if (A[i] > A[i - 1]) {
			B[i] = B[i - 1] + 1;
		}
	}
	for (int i = S - 2; i >= 0; --i) {
		if (A[i] > A[i + 1]) {
			C[i] = C[i + 1] + 1;
		}
	}
	int ret{};
	for (int i = 0; i < S; ++i) {
		if (B[i] >= N && C[i] >= N) {
			++ret;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int S{}, N{}, M{};
	cin >> S >> N >> M;
	vector<int> A(S);
	for (int i = 0; i < S; ++i) {
		cin >> A[i];
	}
	vector<int> B(S);
	for (int i = 0; i < S; ++i) {
		B[i] = -A[i];
	}
	cout << solve(S, A, N) << " " << solve(S, B, M) << "\n";
	return 0;
}
