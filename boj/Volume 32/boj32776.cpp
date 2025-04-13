#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, c{}, d{};
	cin >> a >> b >> c >> d;
	cout << (a <= max(b + c + d, 240) ? "high speed rail" : "flight") << "\n";
	return 0;
}
