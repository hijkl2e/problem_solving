#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, n{};
	cin >> a >> b >> c >> n;
	bool yes = a >= 1 && b >= 1 && c >= 1 && (a + b + c) >= n && n >= 3;
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
