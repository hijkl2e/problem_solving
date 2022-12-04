#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		int prev = -1;
		for (int i = 1; i <= N; ++i) {
			int x{};
			cin >> x;
			if (prev == -1 || prev == x - 1) {
				prev = x;
			} else {
				cout << i << "\n";
			}
		}
	}
	return 0;
}
