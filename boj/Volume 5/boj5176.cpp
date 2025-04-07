#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int P{}, M{};
		cin >> P >> M;
		deque<bool> A(M + 1);
		for (int i = 0; i < P; ++i) {
			int x{};
			cin >> x;
			A[x] = true;
		}
		int ans = P - accumulate(A.begin(), A.end(), 0);
		cout << ans << "\n";
	}
	return 0;
}
