#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const ll INF = 4e18;

vector<ii> C, D;

ll solve(int L, int R, int optL, int optR) {
	if (L > R) {
		return 0;
	}
	ll ret = -INF;
	int j = (L + R) / 2;
	int opt{};
	for (int k = optL; k <= optR; ++k) {
		ll x = D[k].first - C[j].first;
		ll y = D[k].second - C[j].second;
		ll val = x < 0 && y < 0 ? 0 : x * y;
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
	int M{}, N{};
	cin >> M >> N;
	vector<ii> A(M);
	vector<ii> B(N);
	for (int i = 0; i < M; ++i) {
		cin >> A[i].second >> A[i].first;
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i].second >> B[i].first;
	}
	sort(A.begin(), A.end());
	sort(B.rbegin(), B.rend());
	for (int i = 0; i < M; ++i) {
		if (C.empty() || C.back().second > A[i].second) {
			C.push_back(A[i]);
		}
	}
	for (int i = 0; i < N; ++i) {
		if (D.empty() || D.back().second < B[i].second) {
			D.push_back(B[i]);
		}
	}
	reverse(D.begin(), D.end());
	cout << solve(0, C.size() - 1, 0, D.size() - 1) << "\n";
	return 0;
}
