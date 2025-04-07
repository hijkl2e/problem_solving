#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	for (int i = 0; i < 24; ++i) {
		cin >> b;
	}
	cin >> a;
	cout << a - b << "\n";
	cout << a * b << "\n";
	cout << a + b + 1 << "\n";
	return 0;
}
