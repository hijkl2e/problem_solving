#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{};
	cin >> N >> L;
	vector<ll> x(N);
	vector<ll> w(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> w[i];
	}
	double ans{};
	for (int i = 0; i < N; ++i) {
		ans += w[i] * x[i];
	}
	ans /= accumulate(w.begin(), w.end(), 0LL);
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
