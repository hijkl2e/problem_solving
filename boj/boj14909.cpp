#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{}, ans{};
	while (cin >> x) {
		if (x > 0) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
