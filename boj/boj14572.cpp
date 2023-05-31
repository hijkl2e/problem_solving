#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, D{};
	cin >> N >> K >> D;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		int k{};
		cin >> k >> A[i].first;
		while (k--) {
			int x{};
			cin >> x;
			A[i].second |= 1 << (x - 1);
		}
	}
	sort(A.begin(), A.end());
	vector<int> B(K);
	int ans{};
	for (int i = 0, j = 0; j < N; ++j) {
		for (int k = 0; k < K; ++k) {
			if (A[j].second & (1 << k)) {
				++B[k];
			}
		}
		while (A[j].first - A[i].first > D) {
			for (int k = 0; k < K; ++k) {
				if (A[i].second & (1 << k)) {
					--B[k];
				}
			}
			++i;
		}
		ans = max<int>(ans, (K - count(B.begin(), B.end(), 0)
				- count(B.begin(), B.end(), j - i + 1)) * (j - i + 1));
	}
	cout << ans << "\n";
	return 0;
}
