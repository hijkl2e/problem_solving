#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N + 1);
	while (M--) {
		int a{}, b{}, k{};
		cin >> a >> b >> k;
		B[a - 1] += k;
		B[b] -= k;
	}
	partial_sum(B.begin(), B.end(), B.begin());
	for (int i = 0; i < N; ++i) {
		A[i] += B[i];
	}
	for (int i = 0; i < N; ++i) {
		cout << A[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
