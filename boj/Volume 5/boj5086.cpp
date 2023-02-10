#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	while (cin >> a >> b, a) {
		cout << (b % a == 0 ? "factor" : a % b == 0 ? "multiple" : "neither") << "\n";
	}
	return 0;
}
