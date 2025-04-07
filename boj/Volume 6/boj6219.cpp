#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, d{};
	cin >> a >> b >> d;
	deque<bool> P(b + 1, true);
	P[0] = P[1] = false;
	for (int i = 2; i <= b; ++i) {
		if (P[i]) {
			for (int j = 2 * i; j <= b; j += i) {
				P[j] = false;
			}
		}
	}
	int ans{};
	for (int i = a; i <= b; ++i) {
		if (!P[i]) {
			continue;
		}
		int x = i;
		bool flag = false;
		while (x) {
			if (x % 10 == d) {
				flag = true;
				break;
			}
			x /= 10;
		}
		if (flag) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
