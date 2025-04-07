#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, L{};
	cin >> N >> M >> L;
	vector<int> A(N + 2);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	A[N + 1] = L;
	sort(A.begin(), A.end());
	int lo = 0, hi = L;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int cnt{};
		for (int i = 0; i <= N; ++i) {
			cnt += (A[i + 1] - A[i] - 1) / mid;
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
