#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	while (cin >> N >> K) {
		int cnt{}, ans{};
		while (N) {
			ans += N;
			cnt += N;
			N = cnt / K;
			cnt %= K;
		}
		cout << ans << "\n";
	}
	return 0;
}
