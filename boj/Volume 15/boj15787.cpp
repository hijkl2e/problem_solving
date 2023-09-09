#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	while (M--) {
		int q{}, a{}, b{};
		cin >> q >> a;
		--a;
		if (q < 3) {
			cin >> b;
			--b;
			if (q == 1) {
				A[a] |= 1 << b;
			} else {
				A[a] &= ~(1 << b);
			}
		} else if (q == 3) {
			A[a] = (A[a] << 1) & ((1 << 20) - 1);
		} else {
			A[a] >>= 1;
		}
	}
	deque<bool> B(1 << 20);
	for (int i = 0; i < N; ++i) {
		B[A[i]] = true;
	}
	int ans = accumulate(B.begin(), B.end(), 0);
	cout << ans << "\n";
	return 0;
}
