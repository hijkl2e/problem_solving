#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	deque<bool> p(2000001, true);
	p[0] = p[1] = false;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			for (int j = 2 * i; j < p.size(); j += i) {
				p[j] = false;
			}
		}
	}
	vector<int> P;
	for (int i = 2; i < p.size(); ++i) {
		if (p[i]) {
			P.push_back(i);
		}
	}
	int T{};
	cin >> T;
	while (T--) {
		ll x{}, y{};
		cin >> x >> y;
		x += y;
		if (x % 2 == 0) {
			cout << (x > 2 ? "YES" : "NO") << "\n";
			continue;
		}
		x -= 2;
		bool flag = (x > 1);
		for (int k : P) {
			if (x <= k) {
				break;
			} else if (x % k == 0) {
				flag = false;
				break;
			}
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}
	return 0;
}
