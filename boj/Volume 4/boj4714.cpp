#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double x{};
	while (cin >> x, x >= 0) {
		cout << fixed << setprecision(2);
		cout << "Objects weighing " << x << " on Earth will weigh " << 0.167 * x << " on the moon.\n";
	}
	return 0;
}
