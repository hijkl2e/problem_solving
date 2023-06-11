#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, D{}, K{}, C{};
	cin >> N >> D >> K >> C;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(D + 1);
	int cnt{};
	for (int i = 0; i < K; ++i) {
		if (++B[A[i]] == 1) {
			++cnt;
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans = max(ans, cnt + (B[C] == 0));
		if (--B[A[i]] == 0) {
			--cnt;
		}
		if (++B[A[(i + K) % N]] == 1) {
			++cnt;
		}
	}
	cout << ans << "\n";
	return 0;
}
