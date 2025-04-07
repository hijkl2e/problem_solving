#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, X{}, K{};
	cin >> N >> M >> X >> K;
	vector<int> A(K);
	int lo{};
	for (int i = 0; i < K; ++i) {
		int x{};
		cin >> x >> A[i];
		lo = max(lo, x);
	}
	sort(A.begin(), A.end());
	--lo;
	int hi = max(N, M);
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int cnt{};
		for (int i = 0, j = 1; i < K; i = j++) {
			while (j < K && A[j] - A[i] < mid) {
				++j;
			}
			++cnt;
		}
		if (cnt > X) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << hi << "\n";
	return 0;
}
