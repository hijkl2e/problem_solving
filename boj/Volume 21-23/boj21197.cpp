#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	if (N % 2) {
		cout << "still running\n";
		return 0;
	}
	int ans{};
	while (N) {
		int x{}, y{};
		cin >> x >> y;
		ans += y - x;
		N -= 2;
	}
	cout << ans << "\n";
	return 0;
}
