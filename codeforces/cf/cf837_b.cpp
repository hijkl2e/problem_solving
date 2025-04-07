#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		vector<int> A(N + 1);
		while (M--) {
			int x{}, y{};
			cin >> x >> y;
			if (x > y) {
				swap(x, y);
			}
			A[y] = max(A[y], x);
		}
		ll ans{};
		for (int i = 1, j = 1; i <= N; ++i) {
			while (j <= A[i]) {
				++j;
			}
			ans += i - j + 1;
		}
		cout << ans << "\n";
	}
	return 0;
}
