#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(M);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	int r1 = max_element(A.begin(), A.end()) - A.begin();
	int r2 = max_element(A.rbegin(), A.rend()).base() - A.begin() - 1;
	ll ans = (accumulate(A.begin(), A.end(), 0) + (M - 1) * A[r1]) * 1000000000LL
				+ accumulate(B.begin(), B.end(), 0) + r1 * B[0] + (N - r2 - 1) * B[M - 1]
				+ *max_element(B.begin(), B.end()) * (r2 - r1);
	cout << ans << "\n";
	return 0;
}
