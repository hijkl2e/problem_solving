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
	int minv = A[0];
	for (int i = 1; i < N; ++i) {
		B[i] = max(A[i] - minv, B[i - 1]);
		minv = min(minv, A[i]);
	}
	for (int i = 0; i < N; ++i) {
		cout << B[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
