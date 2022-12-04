#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> A[i];
		}
		int g{};
		for (int i = 1; i <= N; ++i) {
			g = gcd(g, A[i]);
		}
		int ans{};
		if (g == 1) {
			ans = 0;
		} else if (gcd(g, gcd(A[N], N)) == 1) {
			ans = 1;
		} else if (gcd(g, gcd(A[N - 1], N - 1)) == 1) {
			ans = 2;
		} else {
			ans = 3;
		}
		cout << ans << "\n";
	}
	return 0;
}
