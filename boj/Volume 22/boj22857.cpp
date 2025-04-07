#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans{};
	int s{}, e{}, cnt{};
	while (e < N) {
		if (A[e++] % 2) {
			++cnt;
		}
		while (cnt > K) {
			if (A[s++] % 2) {
				--cnt;
			}
		}
		ans = max(ans, e - s - cnt);
	}
	cout << ans << "\n";
	return 0;
}
