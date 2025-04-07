#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ll ans = INF;
	for (int k = 0; k < 2; ++k) {
		ll cnt{};
		for (int i = 0, j = 0; i < N; ++i) {
			if (A[i] % 2) {
				cnt += i - j++;
			}
		}
		ans = min(ans, cnt);
		reverse(A.begin(), A.end());
	}
	cout << ans << "\n";
	return 0;
}
