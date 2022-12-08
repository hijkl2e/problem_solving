#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, T{};
	cin >> N >> T;
	vector<int> D(N);
	vector<int> S(N);
	for (int i = 0; i < N; ++i) {
		cin >> D[i] >> S[i];
	}
	double lo = -*min_element(S.begin(), S.end());
	double hi = 1e9;
	for (int i = 0; i < 100; ++i) {
		double mid = (lo + hi) / 2;
		double sum{};
		for (int j = 0; j < N; ++j) {
			sum += D[j] / (S[j] + mid);
		}
		if (sum > T) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << fixed << setprecision(10);
	cout << hi << "\n";
	return 0;
}
