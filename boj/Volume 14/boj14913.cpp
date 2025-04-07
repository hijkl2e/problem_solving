#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, d{}, k{};
	cin >> a >> d >> k;
	if ((k - a + d) % d || (k - a + d) / d < 1) {
		cout << "X\n";
	} else {
		cout << (k - a + d) / d << "\n";
	}
	return 0;
}
