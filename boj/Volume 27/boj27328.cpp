#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	cin >> a >> b;
	cout << (a < b ? -1 : a > b ? 1 : 0) << "\n";
	return 0;
}
