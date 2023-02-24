#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> w(N);
	vector<int> s(N);
	vector<int> e(N);
	for (int i = 0; i < N; ++i) {
		cin >> w[i] >> s[i] >> e[i];
	}
	vector<deque<bool>> A(5, deque<bool>(11));
	int ans{};
	for (int i = 0; i < (1 << N); ++i) {
		int sum{};
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				sum += e[j] - s[j] + 1;
				if (w[j] == 5) {
					sum = -1;
					break;
				}
			}
		}
		if (sum != K) {
			continue;
		}
		for (int j = 1; j < 5; ++j) {
			fill(A[j].begin(), A[j].end(), false);
		}
		bool yes = true;
		for (int j = 0; j < N; ++j) {
			if ((i & (1 << j)) == 0) {
				continue;
			}
			for (int k = s[j]; k <= e[j]; ++k) {
				if (A[w[j]][k]) {
					yes = false;
				}
				A[w[j]][k] = true;
			}
		}
		if (yes) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
