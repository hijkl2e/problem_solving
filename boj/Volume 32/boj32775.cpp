#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{};
	cin >> a >> b;
	cout << (a <= b ? "high speed rail" : "flight") << "\n";
	return 0;
}
