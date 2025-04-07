#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int N, D;
vector<ll> T, V;

ll solve(int L, int R, int optL, int optR) {
	if (L > R) {
		return 0;
	}
	ll ret{};
	int j = (L + R) / 2;
	int opt{};
	for (int k = max(optL, j - D); k <= optR && k <= j; ++k) {
		ll val = V[k] + (j - k) * T[j];
		if (ret < val) {
			ret = val;
			opt = k;
		}
	}
	ret = max(ret, solve(L, j - 1, optL, opt));
	ret = max(ret, solve(j + 1, R, opt, optR));
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> D;
	T.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> T[i];
	}
	V.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> V[i];
	}
	cout << solve(0, N - 1, 0, N - 1) << "\n";
	return 0;
}
