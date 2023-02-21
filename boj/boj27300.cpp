#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, R{};
	cin >> N >> R;
	vector<ll> X(N);
	vector<ll> Y(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
	}
	vector<ld> x(N);
	vector<ld> y(N);
	for (int i = 0; i < N; ++i) {
		x[i] = sqrt(abs(X[i]));
		y[i] = sqrt(abs(Y[i]));
		if (X[i] < 0) {
			x[i] *= -1;
		}
		if (Y[i] < 0) {
			y[i] *= -1;
		}
	}
	ll s1{};
	for (int i = 0; i < N; ++i) {
		s1 += abs(X[i]) + abs(Y[i]);
	}
	ld x_sum = accumulate(x.begin(), x.end(), 0.L);
	ld y_sum = accumulate(y.begin(), y.end(), 0.L);
	ld s2 = (x_sum * x_sum + y_sum * y_sum) / N;
	ld ans = 4 * R - (s1 - s2) * 8 / 3 / (N - 1);
	cout << fixed << setprecision(12);
	cout << ans << "\n";
	return 0;
}
