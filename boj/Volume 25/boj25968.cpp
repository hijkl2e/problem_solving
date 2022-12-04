#include <bits/stdc++.h>

using namespace std;

vector<double> A;

double f(double x) {
	double ret{};
	x *= x;
	for (int i = 0; i < A.size(); ++i) {
		ret = ret * x + A[i];
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.resize(N + 1);
	for (int i = 0; i <= N; ++i) {
		cin >> A[i];
	}
	double lo = -32, hi = 0;
	for (int i = 0; i < 100; ++i) {
		double mid = (lo + hi) / 2;
		if ((f(mid) < 0) ^ (A[N] < 0)) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	int K{};
	cin >> K;
	K = min(K, 10000);
	double len = lo / K;
	double ans{};
	for (int i = 1; i < K; i += 2) {
		ans += len * f(i * len);
	}
	ans = 4 * abs(ans);
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
