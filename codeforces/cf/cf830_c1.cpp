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
		while (Q--) {
			int L{}, R{};
			cin >> L >> R;
			ll maxv = (psum[R] - psum[L - 1]) - (pxor[R] ^ pxor[L - 1]);
			ii ans{L, R};
			int S = L, E = L;
			while (S <= E && E <= R) {
				ll val = (psum[E] - psum[S - 1]) - (pxor[E] ^ pxor[S - 1]);
				if (val == maxv) {
					if (ans.second - ans.first > E - S) {
						ans = {S, E};
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
