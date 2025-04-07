#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	for (int i = 1;; ++i) {
		if (i * i + i + 1 == N) {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
