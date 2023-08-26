#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	cin >> M;
	int d{}, r = 1;
	while (M--) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		r = 1LL * r * b / a;
		d ^= c;
	}
	cout << d << " " << r << "\n";
	return 0;
}
