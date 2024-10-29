#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	--N;
	int p = 1, ans = 1;
	while (N) {
		int x = p + 4 * ans;
		if (N < x) {
			break;
		}
		N -= x;
		p = x;
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
