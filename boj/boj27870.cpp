#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using edge = tuple<int, int, int, int>;

vector<int> G[5][3001][5];
vector<ii> H[5][5];
bitset<3001> A[5][3001][5];

ll solve(int p, int x, int q, int y, int i) {
	ll ret{};
	auto it1 = G[p][x][i].begin();
	auto it2 = G[q][y][i].begin();
	while (it1 != G[p][x][i].end() && it2 != G[q][y][i].end()) {
		if (*it1 < *it2) {
			++it1;
		} else if (*it1 > *it2) {
			++it2;
		} else {
			++ret, ++it1, ++it2;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, M{};
	cin >> N >> M;
	vector<edge> E(M);
	for (int i = 0; i < M; ++i) {
		int p{}, x{}, q{}, y{};
		cin >> p >> x >> q >> y;
		E[i] = {p, x, q, y};
		G[p][x][q].push_back(y);
		G[q][y][p].push_back(x);
		H[p][q].push_back({x, y});
		H[q][p].push_back({y, x});
		A[p][x][q][y] = A[q][y][p][x] = true;
	}
	for (int i = 1; i < 5; ++i) {
		for (int j = 1; j <= N; ++j) {
			for (int k = 1; k < 5; ++k) {
				sort(G[i][j][k].begin(), G[i][j][k].end());
			}
		}
	}
	ll ans = (N * N - M) * N * N;
	for (int i = 1; i < 5; ++i) {
		for (int j = 1; j <= N; ++j) {
			ll cnt = 1;
			for (int k = 1; k < 5; ++k) {
				if (i == k) {
					continue;
				}
				for (int l = k + 1; l < 5; ++l) {
					if (i == l) {
						continue;
					}
					ans += G[i][j][k].size() * G[i][j][l].size() * N;
				}
				cnt *= G[i][j][k].size();
			}
			ans -= cnt;
		}
	}
	for (int i = 1; i < 4; ++i) {
		int u = i % 3 + 1;
		int v = u % 3 + 1;
		ans += H[i][4].size() * H[u][v].size();
		for (int j = 1; j <= N; ++j) {
			for (int k = 1; k <= N; ++k) {
				ans += solve(i, j, 4, k, u) * solve(i, j, 4, k, v);
			}
		}
	}
	ll cnt1{}, cnt2{}, cnt3{};
	for (auto &[p, x, q, y] : E) {
		int i = 1;
		while (p == i || q == i) {
			++i;
		}
		int j = p ^ q ^ i ^ 4;
		ll res1 = solve(p, x, q, y, i);
		ll res2 = solve(p, x, q, y, j);
		ans -= G[p][x][i].size() * G[q][y][j].size()
				+ G[p][x][j].size() * G[q][y][i].size() + res1 * res2;
		cnt1 += res1 + res2;
		cnt2 += res1 * (G[p][x][j].size() + G[q][y][j].size())
				+ res2 * (G[p][x][i].size() + G[q][y][i].size());
		for (auto &[u, v] : H[i][j]) {
			if (A[p][x][i][u] && A[p][x][j][v] && A[q][y][i][u] && A[q][y][j][v]) {
				++cnt3;
			}
		}
	}
	ans += cnt2 / 2 + cnt3 / 6 - cnt1 / 3 * N;
	cout << ans << "\n";
	return 0;
}
