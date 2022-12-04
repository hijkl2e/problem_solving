#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> S(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> S[i] >> B[i];
	}
	int ans = 1e9;
	for (int i = 1; i < (1 << N); ++i) {
		int s = 1, b = 0;
		for (int j = 0; j < N; ++j) {
			if ((i >> j) & 1) {
				s *= S[j];
				b += B[j];
			}
		}
		ans = min(ans, abs(s - b));
	}
	cout << ans << "\n";
	return 0;
}
