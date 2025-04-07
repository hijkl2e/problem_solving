#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		if (A[0] == A[N - 1]) {
			cout << N / 2 << "\n";
			continue;
		}
		ll ans{};
		for (int i = 0, j = 0; i < N; i = j) {
			while (j < N && A[i] == A[j]) {
				++j;
			}
			ans = max(ans, j * (N - j));
		}
		cout << ans << "\n";
	}
	return 0;
}
