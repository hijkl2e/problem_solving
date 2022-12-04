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
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		int g{};
		for (int i = 0; i < N; ++i) {
			g = gcd(g, A[i]);
		}
		int ans = A[N - 1] / g;
		cout << ans << "\n";
	}
	return 0;
}
