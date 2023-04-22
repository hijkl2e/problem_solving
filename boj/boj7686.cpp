#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	while (cin >> N >> K, N) {
		vector<int> P(N);
		vector<int> Q(N);
		for (int i = 0; i < N; ++i) {
			cin >> P[i];
		}
		for (int i = 0; i < N; ++i) {
			cin >> Q[i];
		}
		vector<double> A(N);
		double lo = 0, hi = 1;
		for (int k = 0; k < 30; ++k) {
			double mid = (lo + hi) / 2;
			for (int i = 0; i < N; ++i) {
				A[i] = P[i] - mid * Q[i];
			}
			sort(A.begin(), A.end());
			if (accumulate(A.begin() + K, A.end(), 0.0) < 0) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		int ans = lround(100 * lo);
		cout << ans << "\n";
	}
	return 0;
}
