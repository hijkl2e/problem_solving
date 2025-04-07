#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll N{}, s{}, t{};
		cin >> N >> s >> t;
		vector<int> A;
		while (N) {
			A.push_back(N % 2);
			N /= 2;
		}
		reverse(A.begin(), A.end());
		ll ans = s * accumulate(A.begin(), A.end(), 0);
		for (int i = 0; i < A.size() - 1; ++i) {
			N = 2 * N + A[i];
			ans += s <= t / N ? s * N : t;
		}
		cout << ans << "\n";
	}
	return 0;
}
