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
		for (int i = 2; i * i <= N; ++i) {
			int cnt{};
			while (N % i == 0) {
				N /= i;
				++cnt;
			}
			if (cnt) {
				cout << i << " " << cnt << "\n";
			}
		}
		if (N > 1) {
			cout << N << " 1\n";
		}
	}
	return 0;
}
