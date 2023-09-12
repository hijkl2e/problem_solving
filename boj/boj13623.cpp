#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{};
	cin >> a >> b >> c;
	if ((a + b + c) % 3) {
		int k = 2 - (a + b + c);
		cout << (a == k ? 'A' : b == k ? 'B' : 'C') << "\n";
	} else {
		cout << "*\n";
	}
	return 0;
}
