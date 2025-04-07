#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, K{};
		cin >> N >> K;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		int s = 0, e = N - 1;
		int minv = 1e9;
		int ans{};
		while (s < e) {
			int x = A[s] + A[e] - K;
			int y = abs(x);
			if (minv > y) {
				minv = y;
				ans = 1;
			} else if (minv == y) {
				++ans;
			}
			if (x < 0) {
				++s;
			} else {
				--e;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
