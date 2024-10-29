#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int lo = 0, hi = 20 * N + 1;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int sum{}, cnt{};
		for (int i = 0; i < N; ++i) {
			sum += A[i];
			if (sum >= mid) {
				sum = 0;
				++cnt;
			}
		}
		if (cnt < K) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << lo << "\n";
	return 0;
}
