#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	deque<bool> A(1001);
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; i + j <= N; ++j) {
			for (int k = 0; i + j + k <= N; ++k) {
				int l = N - i - j - k;
				A[i + 5 * j + 10 * k + 50 * l] = true;
			}
		}
	}
	int ans = accumulate(A.begin(), A.end(), 0);
	cout << ans << "\n";
	return 0;
}
