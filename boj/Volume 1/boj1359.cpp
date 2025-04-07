#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		A[i] = i + 1;
	}
	int n{}, d{};
	do {
		int cnt{};
		for (int i = 0; i < M; ++i) {
			if (A[i] <= M) {
				++cnt;
			}
		}
		if (cnt >= K) {
			++n;
		}
		++d;
		reverse(A.begin() + M, A.end());
	} while (next_permutation(A.begin(), A.end()));
	double ans = n * 1.0 / d;
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
