#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{}, F{}, S{}, G{};
	cin >> R >> C >> F >> S >> G;
	vector<vector<ii>> A(F);
	for (int i = 0; i < F; ++i) {
		int K{};
		cin >> K;
		A[i].resize(K);
		for (int j = 0; j < K; ++j) {
			cin >> A[i][j].first >> A[i][j].second;
		}
		sort(A[i].begin(), A[i].end());
	}
	vector<vector<iii>> B(F);
	while (S--) {
		int r{}, c{}, d{}, f{};
		cin >> r >> c >> d >> f;
		B[f - 1].push_back({d, r, c});
	}
	vector<int> T(F);
	for (int i = 0; i < F; ++i) {
		cin >> T[i];
	}
	vector<ll> D(F);
	for (int i = 0; i < F; ++i) {
		sort(B[i].begin(), B[i].end());
		vector<int> E(B[i].size());
		for (int j = 0; j < B[i].size(); ++j) {
			auto &[d, r, c] = B[i][j];
			E[j] = abs(A[i][j].first - r) + abs(A[i][j].second - c);
		}
		sort(E.begin(), E.end());
		D[i] = accumulate(E.begin(), E.begin() + T[i], 0LL);
	}
	sort(D.begin(), D.end());
	ll ans = accumulate(D.begin(), D.begin() + G, 0LL);
	cout << ans << "\n";
	return 0;
}
