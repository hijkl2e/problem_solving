#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n1{}, n2{};
	cin >> n1 >> n2;
	int ans = (n2 - n1 + 360) % 360;
	if (ans > 180) {
		ans -= 360;
	}
	cout << ans << "\n";
	return 0;
}
