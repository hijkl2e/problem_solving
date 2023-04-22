#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> P(N);
	vector<int> Q(N);
	for (int i = 0; i < N; ++i) {
		cin >> P[i] >> Q[i];
	}
	vector<double> A(N);
	double lo = 0, hi = 1;
	for (int k = 0; k < 30; ++k) {
		double mid = (lo + hi) / 2;
		for (int i = 0; i < N; ++i) {
			A[i] = P[i] - mid * Q[i];
		}
		sort(A.rbegin(), A.rend());
		if (accumulate(A.begin(), A.begin() + K, 0.0) < 0) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << fixed << setprecision(10);
	cout << lo << "\n";
	return 0;
}
