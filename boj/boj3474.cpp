#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		int cnt{};
		for (ll i = 5; i <= N; i *= 5) {
			cnt += N / i;
		}
		cout << cnt << "\n";
	}
	return 0;
}
