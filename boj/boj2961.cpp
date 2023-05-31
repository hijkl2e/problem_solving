#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	int ans = 1e9;
	for (int i = 1; i < (1 << N); ++i) {
		int x = 1, y{};
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				x *= A[j];
				y += B[j];
			}
		}
		ans = min(ans, abs(x - y));
	}
	cout << ans << "\n";
	return 0;
}
