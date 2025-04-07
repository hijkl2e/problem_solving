#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;

int N, M, K, ans;
vector<vector<int>> A;
vector<ii> B;

void solve(int n, int s) {
	if (n == K) {
		ans = max(ans, s);
		return;
	}
	int r{}, c{};
	if (B.size()) {
		r = B.back().first;
		c = B.back().second + 1;
	}
	for (int i = r; i < N; ++i) {
		for (int j = i == r ? c : 0; j < M; ++j) {
			bool yes = true;
			for (int k = 0; k < B.size(); ++k) {
				if (abs(B[k].first - i) + abs(B[k].second - j) == 1) {
					yes = false;
					break;
				}
			}
			if (yes) {
				B.push_back({i, j});
				solve(n + 1, s + A[i][j]);
				B.pop_back();
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> K;
	A.assign(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	ans = -INF;
	solve(0, 0);
	cout << ans << "\n";
	return 0;
}
