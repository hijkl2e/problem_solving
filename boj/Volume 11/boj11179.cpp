#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	while (N) {
		ans = 2 * ans + (N & 1);
		N /= 2;
	}
	cout << ans << "\n";
	return 0;
}
