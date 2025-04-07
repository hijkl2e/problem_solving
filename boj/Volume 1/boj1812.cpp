#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		B[0] += (i % 2 ? -1 : 1) * A[i];
	}
	B[0] /= 2;
	for (int i = 1; i < N; ++i) {
		B[i] = A[i - 1] - B[i - 1];
	}
	for (int i = 0; i < N; ++i) {
		cout << B[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
