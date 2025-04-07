#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		-1, 1, 10, 100, 1000, 10000, 100000, 1000000
	};
	int T{};
	cin >> T;
	while (T--) {
		ll a{}, b{}, c{}, K{};
		cin >> a >> b >> c >> K;
		if (max(a, b) > c || max(a, b) + 1 < c) {
			cout << "-1\n";
			continue;
		}
		bool yes{};
		for (int i = A[a]; i < A[a + 1]; ++i) {
			int x = max(A[c] - i, A[b]);
			int y = min(A[c + 1] - i, A[b + 1]) - 1;
			if (x > y) {
				continue;
			} else if (K <= y - x + 1) {
				cout << i << " + " << x + K - 1 << " = " << i + x + K - 1 << "\n";
				yes = true;
				break;
			}
			K -= y - x + 1;
		}
		if (!yes) {
			cout << "-1\n";
		}
	}
	return 0;
}
