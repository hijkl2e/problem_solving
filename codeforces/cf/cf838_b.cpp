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
		cout << N << "\n";
		for (int i = 0; i < N; ++i) {
			int x = 1;
			while (x < A[i]) {
				x *= 2;
			}
			int ans = x - A[i];
			cout << i + 1 << " " << ans << "\n";
		}
	}
	return 0;
}
