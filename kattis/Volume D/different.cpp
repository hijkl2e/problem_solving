#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll a{}, b{};
	while (cin >> a >> b) {
		cout << abs(a - b) << "\n";
	}
	return 0;
}
