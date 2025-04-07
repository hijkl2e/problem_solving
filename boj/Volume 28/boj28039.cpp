#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<ll> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		vector<ll> B;
		for (int i = 0; i < N; ++i) {
			B.push_back(A[i]);
			while (true) {
				int sz = B.size();
				if (sz > 2 && B[sz - 2] >= max(B[sz - 3], B[sz - 1])) {
					B[sz - 3] -= B[sz - 2] - B[sz - 1];
					B.erase(B.end() - 2, B.end());
				} else {
					break;
				}
			}
		}
		int p1 = 0, p2 = B.size() - 1;
		bool flag = true;
		ll cnt{};
		while (p1 <= p2) {
			cnt += (flag ? 1 : -1) * (B[p1] > B[p2] ? B[p1++] : B[p2--]);
			flag ^= true;
		}
		ll ans = (accumulate(A.begin(), A.end(), 0LL) - cnt) / 2 + cnt;
		cout << ans << "\n";
	}
	return 0;
}
