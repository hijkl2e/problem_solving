#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, s{};
	cin >> N >> s;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<queue<ii>> q(2);
	ll sum{}, minv{};
	for (int k = 0; k < 2; ++k) {
		sum = minv = 0;
		for (int i = s - 2 * k; 0 <= i && i < N; i += 1 - 2 * k) {
			sum += A[i];
			minv = min(minv, sum);
			if (sum > 0) {
				q[k].push({-minv, sum});
				sum = minv = 0;
			}
		}
		q[k].push({INF, -1});
	}
	ll ans{};
	while (ans >= min(q[0].front().first, q[1].front().first)) {
		int p = q[0].front().first > q[1].front().first;
		ans += q[p].front().second;
		q[p].pop();
	}
	cout << ans << "\n";
	return 0;
}
