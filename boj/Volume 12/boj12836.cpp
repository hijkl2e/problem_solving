#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<ll> A(N + 1);
	while (Q--) {
		int q{}, x{}, y{};
		cin >> q >> x >> y;
		if (q == 1) {
			A[x] += y;
		} else {
			cout << accumulate(A.begin() + x, A.begin() + y + 1, 0LL) << "\n";
		}
	}
	return 0;
}
