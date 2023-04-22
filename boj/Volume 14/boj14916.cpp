#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	if (N == 1 || N == 3) {
		ans = -1;
	} else {
		if (N % 2) {
			N -= 5;
			++ans;
		}
		ans += N / 10 * 2 + N % 10 / 2;
	}
	cout << ans << "\n";
	return 0;
}
