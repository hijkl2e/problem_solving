#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, S{};
	cin >> N >> S;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int p1{}, p2{}, sum{};
	int ans = N + 1;
	while (true) {
		if (sum < S) {
			if (p2 == N) {
				break;
			}
			sum += A[p2++];
		} else {
			ans = min(ans, p2 - p1);
			sum -= A[p1++];
		}
	}
	ans %= N + 1;
	cout << ans << "\n";
	return 0;
}
