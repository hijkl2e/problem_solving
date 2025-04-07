#include <bits/stdc++.h>

using namespace std;

bool contain7(int x) {
	while (x) {
		if (x % 10 == 7) {
			return true;
		}
		x /= 10;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = 2 * contain7(N) + (N % 7 == 0);
	cout << ans << "\n";
	return 0;
}
