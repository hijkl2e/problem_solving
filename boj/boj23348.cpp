#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, N{};
	cin >> a >> b >> c >> N;
	int maxv{};
	while (N--) {
		int sum{};
		for (int i = 0; i < 3; ++i) {
			int x{}, y{}, z{};
			cin >> x >> y >> z;
			sum += a * x + b * y + c * z;
		}
		maxv = max(maxv, sum);
	}
	cout << maxv << "\n";
	return 0;
}
