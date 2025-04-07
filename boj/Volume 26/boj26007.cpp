#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<int> A(N + 1);
	for (int i = 0; i <= N; ++i) {
		cin >> A[i];
	}
	for (int i = 1; i <= N; ++i) {
		A[i] += A[i - 1];
	}
	vector<int> B(N + 1);
	for (int i = 1; i <= N; ++i) {
		B[i] = B[i - 1] + (A[i] < K);
	}
	while (M--) {
		int l{}, r{};
		cin >> l >> r;
		cout << B[r - 1] - B[l - 1] << "\n";
	}
	return 0;
}
