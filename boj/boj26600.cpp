#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
	vector<int> B(101);
	vector<int> C(101);
	ll a = 1, b = 0;
	int Q{};
	cin >> Q;
	while (Q--) {
		string cmd, op;
		ll x{};
		cin >> cmd >> op >> x;
		if (cmd == "map") {
			if (op == "+") {
				b += x;
				continue;
			} else if (op == "*") {
				a *= x;
				b *= x;
				continue;
			}
			if (A.size()) {
				for (ll y : A) {
					++B[(a * y + b) % x];
				}
				A.clear();
			} else {
				copy(B.begin(), B.end(), C.begin());
				fill(B.begin(), B.end(), 0);
				for (int i = 0; i < C.size(); ++i) {
					B[(a * i + b) % x] += C[i];
				}
			}
			a = 1, b = 0;
			continue;
		}
		int ans{};
		if (A.size()) {
			x -= b;
			if (op == ">=") {
				ans = N - (lower_bound(A.begin(), A.end(), (x - 1) / a + 1) - A.begin());
			} else if (op == "<=") {
				ans = upper_bound(A.begin(), A.end(), x / a) - A.begin();
			} else {
				ans = x % a ? 0 : (upper_bound(A.begin(), A.end(), x / a)
								- lower_bound(A.begin(), A.end(), x / a));
			}
		} else {
			for (int i = 0; i < B.size(); ++i) {
				ll val = a * i + b;
				if (val > x) {
					ans += op == ">=" ? B[i] : 0;
				} else if (val < x) {
					ans += op == "<=" ? B[i] : 0;
				} else {
					ans += B[i];
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
