#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, Q{};
	cin >> N >> Q;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	while (Q--) {
		int q{}, a{}, b{};
		cin >> q >> a >> b;
		ll ans = accumulate(A.begin() + a, A.begin() + b + 1, 0LL);
		if (q == 1) {
			swap(A[a], A[b]);
		} else {
			int c{}, d{};
			cin >> c >> d;
			ans -= accumulate(A.begin() + c, A.begin() + d + 1, 0LL);
		}
		cout << ans << "\n";
	}
	return 0;
}
