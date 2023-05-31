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
	int lo = -1, hi = 1e4;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int maxv{}, minv{}, cnt{};
		maxv = minv = A[0], cnt = 1;
		for (int i = 0; i < N; ++i) {
			if (max(maxv, A[i]) - min(minv, A[i]) > mid) {
				maxv = minv = A[i], ++cnt;
			} else {
				maxv = max(maxv, A[i]);
				minv = min(minv, A[i]);
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
