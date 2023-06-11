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
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	int ans{};
	for (int i = 0; i < (1 << N); ++i) {
		int x = 100, y = 0;
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				x -= A[j];
				y += B[j];
			}
		}
		if (x > 0) {
			ans = max(ans, y);
		}
	}
	cout << ans << "\n";
	return 0;
}
