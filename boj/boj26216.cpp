#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int K, H;

int h(ll x) {
	int ret = H - 1;
	while (x % (K + 1) == K) {
		--ret;
		x /= K + 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int Q{};
	cin >> K >> H >> Q;
	vector<ll> sz(H);
	sz[H - 1] = K + 1;
	for (int i = H - 2; i >= 0; --i) {
		sz[i] = (K + 1) * sz[i + 1];
	}
	while (Q--) {
		ll A{}, B{};
		cin >> A >> B;
		if (max(A, B) >= sz[0]) {
			cout << "-1\n";
			continue;
		} else if (A == B) {
			cout << "0\n";
			continue;
		}
		int ha = h(--A), hb = h(--B);
		A = A - A % sz[ha--];
		B = B - B % sz[hb--];
		int ans = 2;
		while (A != B || ha != hb) {
			if (ha > hb) {
				A = A - A % sz[ha--];
			} else {
				B = B - B % sz[hb--];
			}
			++ans;
		}
		cout << ans << "\n";
	}
	return 0;
}
