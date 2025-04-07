#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, Pi{}, Pj{};
	cin >> N >> Pi >> Pj;
	map<int, vector<int>> S;
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		S[y].push_back(x);
	}
	for (auto &[y, v] : S) {
		if (v.size() > 2 || (v.size() == 2 && abs(v[0] - v[1]) > 1)
				|| (y == 1 && (v.size() > 1 || abs(v[0]) > 1))) {
			cout << "-1\n";
			return 0;
		}
		sort(v.begin(), v.end());
	}
	if (S.begin()->first > 1) {
		S[0].push_back(0);
	}
	vector<vector<ll>> dp(S.size(), vector<ll>(2, INF));
	dp[0][0] = abs(S.begin()->second[0]) * Pi;
	auto it1 = S.begin();
	auto it2 = ++S.begin();
	for (int i = 1; i < S.size(); ++i) {
		auto &[y1, v1] = *it1;
		auto &[y2, v2] = *it2;
		int ydf = y2 - y1;
		if (v1.size() == 1) {
			if (v2.size() == 1) {
				int xdf = abs(v1[0] - v2[0]);
				if (xdf <= ydf + 1) {
					dp[i][0] = dp[i - 1][xdf == ydf + 1] + xdf * Pi;
					if (xdf <= ydf) {
						dp[i][1] = dp[i - 1][xdf == ydf] + xdf * Pi + Pj;
					}
				}
			} else {
				for (int j = 0; j < 2; ++j) {
					int xdf = abs(v1[0] - v2[j ^ 1]);
					if (xdf <= ydf) {
						dp[i][j] = dp[i - 1][xdf == ydf] + (xdf + 1) * Pi + Pj;
					}
				}
			}
		} else {
			if (v2.size() == 1) {
				for (int j = 0; j < 2; ++j) {
					int xdf = abs(v1[j] - v2[0]);
					if (xdf <= ydf) {
						dp[i][0] = min(dp[i][0], dp[i - 1][j] + xdf * Pi);
						if (xdf < ydf) {
							dp[i][1] = min(dp[i][1], dp[i - 1][j] + xdf * Pi + Pj);
						}
					}
				}
			} else {
				for (int j = 0; j < 2; ++j) {
					for (int k = 0; k < 2; ++k) {
						int xdf = abs(v1[j] - v2[k ^ 1]);
						if (xdf < ydf) {
							dp[i][k] = min(dp[i][k], dp[i - 1][j] + (xdf + 1) * Pi + Pj);
						}
					}
				}
			}
		}
		++it1, ++it2;
	}
	ll ans = min(dp[S.size() - 1][0], dp[S.size() - 1][1]);
	cout << (ans < INF ? ans : -1) << "\n";
	return 0;
}
