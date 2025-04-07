#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	int M{};
	cin >> M;
	vector<int> C(M);
	vector<int> D(M);
	for (int i = 0; i < M; ++i) {
		cin >> C[i] >> D[i];
	}
	int lo = 1, hi = 1e9;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		ll sum = 1;
		for (int i = 0; i < N; ++i) {
			if (mid > A[i]) {
				sum += (mid - A[i] - 1) / B[i] + 1;
			}
		}
		for (int i = 0; i < M; ++i) {
			if (T - mid >= C[i]) {
				sum -= (T - mid - C[i]) / D[i] + 1;
			}
		}
		if (sum > 0) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << lo << "\n";
	return 0;
}
