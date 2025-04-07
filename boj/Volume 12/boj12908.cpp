#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

ll dist(ll x1, ll y1, ll x2, ll y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> X(8);
	vector<ll> Y(8);
	for (int i = 0; i < 8; ++i) {
		cin >> X[i] >> Y[i];
	}
	vector<int> A(3);
	vector<int> B{0, 1, 2};
	ll ans = INF;
	for (A[0] = 0; A[0] < 3; ++A[0]) {
		for (A[1] = 0; A[1] < 3; ++A[1]) {
			for (A[2] = 0; A[2] < 3; ++A[2]) {
				B = {0, 1, 2};
				do {
					ll x = X[0], y = Y[0], cnt{};
					for (int i = 0; i < 3; ++i) {
						int k = B[i];
						if (A[k]) {
							int z = 2 * k + A[k] + 1;
							cnt += dist(x, y, X[z], Y[z]) + 10;
							x = X[z ^ 1], y = Y[z ^ 1];
						}
					}
					cnt += dist(x, y, X[1], Y[1]);
					ans = min(ans, cnt);
				} while (next_permutation(B.begin(), B.end()));
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
