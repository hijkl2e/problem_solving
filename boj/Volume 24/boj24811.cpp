#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int now{}, prev{}, cnt{}, ans{};
	now = prev = 20;
	while (N--) {
		int x{};
		cin >> x;
		now += x;
		if (now >= 100) {
			ans = 1;
			break;
		} else if (now <= 0) {
			ans = 2;
			break;
		}
		if (now >= prev + 10) {
			prev = now;
			cnt = 0;
		} else if (++cnt == 4) {
			break;
		}
	}
	cout << (ans == 1 ? "Touchdown" : ans == 2 ? "Safety" : "Nothing") << "\n";
	return 0;
}
