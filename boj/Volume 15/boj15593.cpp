#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	vector<int> C(1001);
	for (int i = 0; i < N; ++i) {
		++C[A[i]], --C[B[i]];
	}
	partial_sum(C.begin(), C.end(), C.begin());
	int minv = 1e9;
	for (int i = 0; i < N; ++i) {
		minv = min<int>(minv, count(C.begin() + A[i], C.begin() + B[i], 1));
	}
	int ans = C.size() - count(C.begin(), C.end(), 0) - minv;
	cout << ans << "\n";
	return 0;
}
