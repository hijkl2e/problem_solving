#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int K{};
		double d{}, a{}, b{}, f{};
		cin >> K >> d >> a >> b >> f;
		cout << fixed << setprecision(10);
		cout << K << " " << d / (a + b) * f << "\n";
	}
	return 0;
}
