#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int s1{}, s2{};
	cin >> s1 >> s2;
	cout << (2 * s1 >= s2 ? "E" : "H") << "\n";
	return 0;
}
