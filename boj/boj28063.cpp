#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, x{}, y{};
	cin >> N >> x >> y;
	int ans = (x > 1) + (x < N) + (y > 1) + (y < N);
	cout << ans << "\n";
	return 0;
}
