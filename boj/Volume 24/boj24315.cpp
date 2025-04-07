#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a1{}, a0{}, c1{}, c2{}, n0{};
	cin >> a1 >> a0 >> c1 >> c2 >> n0;
	bool yes = n0 * (a1 - c1) >= max(-a0, 0) && n0 * (c2 - a1) >= max(a0, 0);
	cout << yes << "\n";
	return 0;
}
