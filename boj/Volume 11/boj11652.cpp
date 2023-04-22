#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 5e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	ll ans = -INF;
	int cnt{}, maxc{};
	for (int i = 0; i < N; ++i) {
		if (i && A[i - 1] == A[i]) {
			++cnt;
		} else {
			if (maxc < cnt) {
				maxc = cnt;
				ans = A[i - 1];
			}
			cnt = 1;
		}
	}
	if (maxc < cnt) {
		ans = A[N - 1];
	}
	cout << ans << "\n";
	return 0;
}
