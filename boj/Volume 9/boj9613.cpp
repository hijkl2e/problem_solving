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
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		ll ans{};
		for (int i = 0; i < N; ++i) {
			for (int j = i + 1; j < N; ++j) {
				ans += gcd(A[i], A[j]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
