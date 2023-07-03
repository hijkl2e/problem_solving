#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, w{}, h{}, L{};
	cin >> N >> w >> h >> L;
	int ans = min((w / L) * (h / L), N);
	cout << ans << "\n";
	return 0;
}
