#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, a{}, b{}, c{}, d{};
	cin >> N >> a >> b >> c >> d;
	int ans = min(((N - 1) / a + 1) * b, ((N - 1) / c + 1) * d);
	cout << ans << "\n";
	return 0;
}
