#include <bits/stdc++.h>

using namespace std;

using ll = long long;

double dist(ll x1, ll y1, ll x2, ll y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<ll> x(N + 1);
	vector<ll> y(N + 1);
	for (int i = 0; i < N; ++i) {
		cin >> x[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> y[i];
	}
	vector<double> A(N);
	vector<double> B(N);
	for (int i = 1; i < N; ++i) {
		A[i] = B[i] = dist(x[i - 1], y[i - 1], x[i], y[i]);
		A[i] *= y[i - 1] < y[i] ? 3 : y[i - 1] == y[i] ? 2 : 1;
		B[i] *= y[i - 1] < y[i] ? 1 : y[i - 1] == y[i] ? 2 : 3;
	}
	partial_sum(A.begin(), A.end(), A.begin());
	partial_sum(B.begin(), B.end(), B.begin());
	while (Q--) {
		int a{}, b{};
		cin >> a >> b;
		--a, --b;
		double ans{};
		if (a < b) {
			ans = A[b] - A[a];
		} else {
			ans = B[a] - B[b];
		}
		cout << fixed << setprecision(10);
		cout << ans << "\n";
	}
	return 0;
}
