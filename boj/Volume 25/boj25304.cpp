#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int X{}, N{};
	cin >> X >> N;
	while (N--) {
		int a{}, b{};
		cin >> a >> b;
		X -= a * b;
	}
	cout << (X == 0 ? "Yes" : "No") << "\n";
	return 0;
}
