#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	while (cin >> a >> b, a) {
		cout << (a > b ? "Yes" : "No") << "\n";
	}
	return 0;
}
