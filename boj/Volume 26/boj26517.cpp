#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll k{}, a{}, b{}, c{}, d{};
	cin >> k >> a >> b >> c >> d;
	if (a * k + b == c * k + d) {
		cout << "Yes " << a * k + b << "\n";
	} else {
		cout << "No\n";
	}
	return 0;
}
