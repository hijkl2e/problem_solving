#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(N);
	vector<int> C(M);
	vector<int> D(M);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	for (int i = 0; i < M; ++i) {
		cin >> C[i] >> D[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	partial_sum(C.begin(), C.end(), C.begin());
	int ans{};
	for (int i = 0, j = 0, k = 0; i < 100; ++i) {
		if (A[j] == i) {
			++j;
		}
		if (C[k] == i) {
			++k;
		}
		ans = max(ans, max(D[k] - B[j], 0));
	}
	cout << ans << "\n";
	return 0;
}
