#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int S{}, N{};
	cin >> S >> N;
	int init{}, prev_x{};
	cin >> init;
	prev_x = init;
	int ans{};
	while (--N) {
		int x{};
		cin >> x;
		ans += (x - prev_x) / 2 - 1;
		prev_x = x;
	}
	ans += (S + init - prev_x) / 2 - 1;
	cout << ans << "\n";
	return 0;
}
