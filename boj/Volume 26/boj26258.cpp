#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> x(N);
	vector<ll> y(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
		x[i] *= 10;
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		double k{};
		cin >> k;
		ll z = 10 * k + EPS;
		int p = upper_bound(x.begin(), x.end(), z) - x.begin();
		cout << (y[p - 1] < y[p] ? 1 : y[p - 1] > y[p] ? -1 : 0) << "\n";
	}
	return 0;
}
