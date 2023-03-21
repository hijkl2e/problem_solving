#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{};
	cin >> N >> T;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N);
	vector<int> C(N);
	int lo = -1, hi = 1e9;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		copy(A.begin(), A.end(), B.begin());
		ll cnt{};
		for (int i = 1; i < N; ++i) {
			if (B[i] - B[i - 1] > mid) {
				cnt += B[i] - B[i - 1] - mid;
				B[i] = B[i - 1] + mid;
			}
		}
		for (int i = N - 2; i >= 0; --i) {
			if (B[i] - B[i + 1] > mid) {
				cnt += B[i] - B[i + 1] - mid;
				B[i] = B[i + 1] + mid;
			}
		}
		if (cnt > T) {
			lo = mid;
		} else {
			hi = mid;
			copy(B.begin(), B.end(), C.begin());
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << C[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
