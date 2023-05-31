#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int N, M;
vector<int> A;

ll solve(ll t) {
	if (t == 0) {
		return 0;
	}
	ll ret{};
	for (int i = 0; i < M; ++i) {
		ret += (t - 1) / A[i] + 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	A.resize(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	ll lo = 0, hi = 6e10;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		ll cnt = solve(mid);
		if (cnt < N) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	N -= solve(lo);
	int ans{};
	for (int i = 0; i < M; ++i) {
		if (lo % A[i] == 0 && --N == 0) {
			ans = i + 1;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
