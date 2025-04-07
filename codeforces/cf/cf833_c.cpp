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
		vector<ll> A(N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
		}
		vector<ll> psum(N + 1);
		partial_sum(A.begin(), A.end(), psum.begin());
		map<ll, int> B;
		int ans{};
		for (int i = N; i > 0; --i) {
			++B[psum[i]];
			if (A[i]) {
				continue;
			}
			int maxv{};
			for (auto &p : B) {
				maxv = max(maxv, p.second);
			}
			ans += maxv;
			B.clear();
		}
		ans += B[0];
		cout << ans << "\n";
	}
	return 0;
}
