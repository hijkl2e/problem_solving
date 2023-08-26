#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{};
	cin >> a >> b >> c;
	cout << (a + 2 * b + 3 * c >= 10 ? "happy" : "sad") << "\n";
	return 0;
}
