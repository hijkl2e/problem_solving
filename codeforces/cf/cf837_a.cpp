#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		int minv = *min_element(A.begin(), A.end());
		int maxv = *max_element(A.begin(), A.end());
		ll cnt1 = count(A.begin(), A.end(), minv);
		ll cnt2 = count(A.begin(), A.end(), maxv);
		ll ans = minv == maxv ? N * (N - 1) : (2 * cnt1 * cnt2);
		cout << ans << "\n";
	}
	return 0;
}
