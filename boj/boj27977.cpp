#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{}, N{}, K{};
	cin >> L >> N >> K;
	vector<int> A(N + 2);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	A[N + 1] = L;
	int maxv{};
	for (int i = 0; i <= N; ++i) {
		maxv = max(maxv, A[i + 1] - A[i]);
	}
	int lo = maxv - 1, hi = L;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int cnt = -1;
		for (int i = 0, j = 0; i <= N; i = j++) {
			while (j <= N && A[j + 1] - A[i] <= mid) {
				++j;
			}
			++cnt;
		}
		if (cnt > K) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << hi << "\n";
	return 0;
}
