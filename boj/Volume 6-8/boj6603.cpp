#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 0; cin >> N, N; ++tc) {
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		if (tc) {
			cout << "\n";
		}
		for (int i = (1 << N) - 1; i >= 0; --i) {
			if (__builtin_popcount(i) != 6) {
				continue;
			}
			vector<int> B;
			for (int j = N - 1; j >= 0; --j) {
				if (i & (1 << j)) {
					B.push_back(A[N - j - 1]);
				}
			}
			for (int j = 0; j < 6; ++j) {
				cout << B[j] << (j == 5 ? "\n" : " ");
			}
		}
	}
	return 0;
}
