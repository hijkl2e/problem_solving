#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int M{};
	cin >> M;
	int lo = 1, hi = *max_element(A.begin(), A.end()) + 1;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		int sum{};
		for (int i = 0; i < N; ++i) {
			sum += min(A[i], mid);
		}
		if (sum > M) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << lo << "\n";
	return 0;
}
