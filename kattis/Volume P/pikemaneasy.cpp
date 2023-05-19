#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const ll MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, T{}, A{}, B{}, C{}, t{};
	cin >> N >> T >> A >> B >> C >> t;
	vector<ll> D(C + 1, -1);
	D[t] = 0;
	int len = -1;
	for (int i = 1; i < N; ++i) {
		t = (A * t + B) % C + 1;
		if (D[t] == -1) {
			D[t] = i;
		} else {
			len = i - D[t];
			break;
		}
	}
	vector<ll> E(C + 1);
	for (int i = 1; i <= C; ++i) {
		if (D[i] == -1) {
			continue;
		}
		E[i] = len == -1 || D[i] < D[t] ? 1 : ((N - D[i] - 1) / len + 1);
	}
	ii ans;
	ll now{};
	for (int i = 1; i <= C; ++i) {
		ll x = min(E[i], (T - now) / i);
		ans.first += x;
		ans.second += now % MOD * x % MOD + x * (x + 1) / 2 % MOD * i % MOD;
		now += x * i;
	}
	ans.second %= MOD;
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}
