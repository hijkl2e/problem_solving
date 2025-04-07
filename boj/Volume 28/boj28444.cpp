#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int h{}, i{}, a{}, r{}, c{};
	cin >> h >> i >> a >> r >> c;
	int ans = h * i - a * r * c;
	cout << ans << "\n";
	return 0;
}
