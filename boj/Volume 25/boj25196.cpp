#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> V(3);
	vector<int> S(3);
	vector<int> E(3);
	for (int i = 0; i < 3; ++i) {
		cin >> V[i] >> S[i] >> E[i];
	}
	ll ans = INF;
	for (int i = 0; i < 3; ++i) {
		int u = (i + 1) % 3;
		int v = (i + 2) % 3;
		ll t = S[i];
		for (int j = lcm(V[u], V[v]); j > 0; --j) {
			int x = t % V[u];
			int y = t % V[v];
			if (S[u] <= x && x <= E[u] && S[v] <= y && y <= E[v]) {
				ans = min(ans, t);
				break;
			}
			t += V[i];
		}
	}
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}
