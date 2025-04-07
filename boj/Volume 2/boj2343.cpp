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
	int maxv = *max_element(A.begin(), A.end());
	int lo = maxv - 1, hi = N * maxv;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int sum{}, cnt = 1;
		for (int i = 0; i < N; ++i) {
			sum += A[i];
			if (sum > mid) {
				sum = A[i];
				++cnt;
			}
		}
		if (cnt > M) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << hi << "\n";
	return 0;
}
