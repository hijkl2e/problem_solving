#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, D{};
	cin >> N >> K >> D;
	vector<int> A(K);
	vector<int> B(K);
	vector<int> C(K);
	for (int i = 0; i < K; ++i) {
		cin >> A[i] >> B[i] >> C[i];
	}
	int lo = 0, hi = N;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		ll cnt{};
		for (int i = 0; i < K; ++i) {
			if (mid < A[i]) {
				continue;
			}
			cnt += (min(B[i], mid) - A[i]) / C[i] + 1;
		}
		if (cnt < D) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << hi << "\n";
	return 0;
}
