#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a1{}, a0{}, c{}, n0{};
	cin >> a1 >> a0 >> c >> n0;
	bool yes = n0 * (c - a1) >= max(a0, 0);
	cout << yes << "\n";
	return 0;
}
