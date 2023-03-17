#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const ll INF = 4e18;

vector<ii> B, C;

ll solve(int L, int R, int optL, int optR) {
	if (L > R) {
		return 0;
	}
	ll ret = -INF;
	int j = (L + R) / 2;
	int opt{};
	for (int k = optL; k <= optR; ++k) {
		ll val = (B[j].first + C[k].first) * (C[k].second - B[j].second);
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
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		if (B.empty() || B.back().first < A[i]) {
			B.push_back({A[i], i});
		}
	}
	for (int i = N - 1; i >= 0; --i) {
		if (C.empty() || C.back().first < A[i]) {
			C.push_back({A[i], i});
		}
	}
	reverse(C.begin(), C.end());
	cout << solve(0, B.size() - 1, 0, C.size() - 1) << "\n";
	return 0;
}
