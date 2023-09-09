#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int D{}, N{};
	cin >> D >> N;
	vector<int> A(D);
	for (int i = 0; i < D; ++i) {
		cin >> A[i];
	}
	for (int i = 1; i < D; ++i) {
		A[i] = min(A[i], A[i - 1]);
	}
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	int p = D - 1;
	for (int i = 0; i < N; ++i) {
		while (p >= 0 && A[p] < B[i]) {
			--p;
		}
		--p;
	}
	int ans = max(p + 2, 0);
	cout << ans << "\n";
	return 0;
}
