#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	int ans{};
	for (int i = N;; ++i) {
		if (__builtin_popcount(i) <= K) {
			ans = i - N;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
