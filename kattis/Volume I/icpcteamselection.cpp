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
		vector<int> A(3 * N);
		for (int i = 0; i < A.size(); ++i) {
			cin >> A[i];
		}
		sort(A.rbegin(), A.rend());
		int ans{};
		for (int i = 0; i < N; ++i) {
			ans += A[2 * i + 1];
		}
		cout << ans << "\n";
	}
	return 0;
}
