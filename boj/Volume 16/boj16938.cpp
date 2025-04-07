#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, L{}, R{}, X{};
	cin >> N >> L >> R >> X;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int ans{};
	for (int i = 0; i < (1 << N); ++i) {
		if (__builtin_popcount(i) < 2) {
			continue;
		}
		int sum{}, minv{}, maxv{};
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				sum += A[j];
				if (minv == 0) {
					minv = A[j];
				}
				maxv = A[j];
			}
		}
		if (L <= sum && sum <= R && maxv - minv >= X) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
