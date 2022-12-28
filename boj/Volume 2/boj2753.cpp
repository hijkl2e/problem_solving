#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x{};
	cin >> x;
	cout << ((x % 4 == 0 && x % 100) || x % 400 == 0) << "\n";
	return 0;
}
