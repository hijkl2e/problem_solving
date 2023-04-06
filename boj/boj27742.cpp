#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using rec = tuple<ll, ll, ll, int>;

vector<vector<ll>> A(5, vector<ll>(5));

bool solve(int T) {
	vector<rec> B(4);
	for (int i = 1; i < 5; ++i) {
		auto &[a, b, c, d] = B[i - 1];
		d = i;
		for (int j = 1; j < 5; ++j) {
			if (i == j) {
				continue;
			}
			ll x = A[i][j] - A[j][i];
			a -= x > 0 ? 3 : x == 0 ? 1 : 0;
			b -= x;
			c -= A[i][j];
		}
	}
	sort(B.begin(), B.end());
	return get<3>(B[0]) == T || get<3>(B[1]) == T;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll T{}, K{};
	cin >> T >> K;
	int x{};
	for (int i = 1; i < 5; ++i) {
		for (int j = 1; j < 5; ++j) {
			cin >> A[i][j];
			if (A[i][j] == -1) {
				x = j;
			}
		}
	}
	ll lo = -1, hi = K + 1;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		A[T][x] = mid;
		if (solve(T)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << (hi == K + 1 ? -1 : hi) << "\n";
	return 0;
}
