#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	while (N--) {
		int X{}, Y{};
		cin >> X >> Y;
		int K{};
		cin >> K;
		int g{};
		while (K--) {
			int x{};
			cin >> x;
			g = gcd(g, x);
		}
		cout << ((X % g == 0 && Y % g == 0) ? "Ta-da" : "Gave up") << "\n";
	}
	return 0;
}
