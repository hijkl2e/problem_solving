#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int X{}, Y{};
	cin >> X >> Y;
	ll sum{}, ans{};
	while (sum < Y - X) {
		sum += ans++ / 2 + 1;
	}
	cout << ans << "\n";
	return 0;
}
