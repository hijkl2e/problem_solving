#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	while (N--) {
		int x{};
		cin >> x;
		if (x % 2) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
