#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int prev_x{}, ans{};
	while (N--) {
		int x{};
		cin >> x;
		if (prev_x < x) {
			++ans;
		}
		prev_x = x;
	}
	cout << ans << "\n";
	return 0;
}
