#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, a{}, b{};
	cin >> N >> a >> b;
	int ans = 4 * max(a, N - a) * max(b, N - b);
	cout << ans << "\n";
	return 0;
}
