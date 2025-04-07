#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	for (int i = 1;; ++i) {
		if (N < i) {
			ans = i % 2 ? i - N : 0;
			break;
		}
		N -= i;
	}
	cout << ans << "\n";
	return 0;
}
