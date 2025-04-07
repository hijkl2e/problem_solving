#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = 1 << (31 - __builtin_clz(N));
	cout << ans << "\n";
	return 0;
}
