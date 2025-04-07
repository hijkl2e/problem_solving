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
	int lo = *max_element(A.begin(), A.end()) - 1, hi = 1e9;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int x{}, cnt{};
		for (int i = 0; i < N; ++i) {
			if (x < A[i]) {
				x = mid;
				++cnt;
			}
			x -= A[i];
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
