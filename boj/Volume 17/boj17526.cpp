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
	return (l1.b - l2.b) * 1.0 / (l2.a - l1.a);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	--N;
	vector<ll> D(N);
	for (int i = N - 1; i >= 0; --i) {
		cin >> D[i];
	}
	partial_sum(D.begin(), D.end(), D.begin());
	vector<ll> P(N);
	vector<ll> S(N);
	for (int i = N - 1; i >= 0; --i) {
		cin >> P[i] >> S[i];
	}
	vector<line> A;
	A.push_back({0, 0, -INF});
	ll ans{};
	for (int i = 0; i < N; ++i) {
		int lo = 0, hi = A.size();
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			if (A[mid].c - EPS < S[i]) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		ans = A[lo].a * S[i] + A[lo].b + D[i] * S[i] + P[i];
		line L{-D[i], ans, -INF};
		while (A.size()) {
			L.c = get_x(L, A.back());
			if (L.c < A.back().c - EPS) {
				A.pop_back();
			} else {
				break;
			}
		}
		A.push_back(L);
	}
	cout << ans << "\n";
	return 0;
}
