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
		int sum = accumulate(A.begin(), A.end(), 0);
		if (sum % 2 == 0) {
			cout << "0\n";
			continue;
		}
		int ans = 1e9;
		for (int i = 0; i < N; ++i) {
			int x = A[i];
			int cnt{};
			while ((A[i] - x) % 2 == 0) {
				x /= 2;
				++cnt;
			}
			ans = min(ans, cnt);
		}
		cout << ans << "\n";
	}
	return 0;
}
