#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, F{};
	cin >> N >> F;
	vector<int> A(N);
	A[0] = 1;
	for (int i = 1; i < N; ++i) {
		A[i] = A[i - 1] * (N - i) / i;
	}
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		B[i] = i + 1;
	}
	do {
		int sum{};
		for (int i = 0; i < N; ++i) {
			sum += A[i] * B[i];
		}
		if (sum == F) {
			break;
		}
	} while (next_permutation(B.begin(), B.end()));
	for (int i = 0; i < N; ++i) {
		cout << B[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
