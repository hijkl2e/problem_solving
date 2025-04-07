#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll INF = 4e18;

int N;
vector<int> A;
vector<ii> B;

void dfs(int x, int d) {
	if (2 * x <= N) {
		dfs(2 * x, d + 1);
	}
	B.push_back({A[x], d});
	if (2 * x + 1 <= N) {
		dfs(2 * x + 1, d + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	dfs(1, 0);
	int d = __builtin_ctz(N + 1);
	ll ans = -INF;
	for (int i = 0; i < d; ++i) {
		for (int j = i; j < d; ++j) {
			ll sum{};
			for (auto &[x, y] : B) {
				if (i <= y && y <= j) {
					sum = max(sum, 0LL) + x;
					ans = max(ans, sum);
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
