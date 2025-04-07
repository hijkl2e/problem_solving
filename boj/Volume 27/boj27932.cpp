#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int lo = -1, hi = INF;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int cnt{};
		for (int i = 0; i < N; ++i) {
			if ((i && abs(A[i] - A[i - 1]) > mid) || (i < N - 1 && abs(A[i] - A[i + 1]) > mid)) {
				++cnt;
			}
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
