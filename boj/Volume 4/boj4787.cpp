#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;
const double EPS = 1e-9;

struct line {
	ll a{}, b{};
	double c{};
};

double get_x(line &l1, line &l2) {
	return (l2.b - l1.b) * 1.0 / (l1.a - l2.a);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, c{};
	while (cin >> N >> c, N) {
		vector<ll> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		vector<line> B;
		ll ans{};
		for (int i = 0, j = 0; i < N; ++i) {
			line L{-2 * A[i], ans + A[i] * A[i], -INF};
			while (B.size()) {
				L.c = get_x(L, B.back());
				if (L.c < B.back().c - EPS) {
					B.pop_back();
				} else {
					break;
				}
			}
			B.push_back(L);
			while (j + 1 < B.size() && B[j + 1].c - EPS < A[i]) {
				++j;
			}
			ans = B[j].a * A[i] + B[j].b + A[i] * A[i] + c;
		}
		cout << ans << "\n";
	}
	return 0;
}
