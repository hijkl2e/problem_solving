#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, Q{};
		cin >> N >> Q;
		vector<ll> A(N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
		}
		vector<ll> psum(N + 1);
		vector<ll> pxor(N + 1);
		for (int i = 1; i <= N; ++i) {
			psum[i] = psum[i - 1] + A[i];
			pxor[i] = pxor[i - 1] ^ A[i];
		}
		vector<int> B;
		for (int i = 1; i <= N; ++i) {
			if (A[i]) {
				B.push_back(i);
			}
		}
		while (Q--) {
			int L{}, R{};
			cin >> L >> R;
			ll maxv = (psum[R] - psum[L - 1]) - (pxor[R] ^ pxor[L - 1]);
			ii ans{L, R};
			L = lower_bound(B.begin(), B.end(), L) - B.begin();
			R = upper_bound(B.begin(), B.end(), R) - B.begin() - 1;
			if (L > R) {
				cout << ans.first << " " << ans.first << "\n";
				continue;
			}
			int S = L, E = max(R - 30, L);
			while (S <= E && E <= R) {
				int s = B[S], e = B[E];
				ll val = (psum[e] - psum[s - 1]) - (pxor[e] ^ pxor[s - 1]);
				if (val == maxv) {
					if (ans.second - ans.first > e - s) {
						ans = {s, e};
					}
					++S;
				} else {
					++E;
				}
			}
			cout << ans.first << " " << ans.second << "\n";
		}
	}
	return 0;
}
