#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	if (M * K < N || N < M + K - 1) {
		cout << "-1\n";
		return 0;
	}
	vector<int> A(M + 1);
	for (int i = 1; i <= M; ++i) {
		A[i] = min(N - M + i, K);
		N -= A[i];
		A[i] += A[i - 1];
	}
	vector<int> B;
	for (int i = 1; i <= M; ++i) {
		for (int j = A[i]; j > A[i - 1]; --j) {
			B.push_back(j);
		}
	}
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}
