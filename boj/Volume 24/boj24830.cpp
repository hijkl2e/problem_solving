#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	ll prev = 1;
	while (N--) {
		ll a{}, b{};
		char op{};
		cin >> a >> op >> b;
		ll res{};
		if (op == '+') {
			res = (a + b) - prev;
		} else if (op == '-') {
			res = (a - b) * prev;
		} else if (op == '*') {
			res = a * b;
			res *= res;
		} else {
			res = (a + 1) / 2;
		}
		cout << res << "\n";
		prev = res;
	}
	return 0;
}
