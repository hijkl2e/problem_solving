#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int p1{}, s1{}, s2{}, p2{};
	cin >> p1 >> s1 >> s2 >> p2;
	int ans{};
	if (p1 + p2 > s1 + s2) {
		ans = 1;
	} else if (p1 + p2 < s1 + s2) {
		ans = 2;
	} else {
		ans = p2 > s1 ? 1 : p2 < s1 ? 2 : 0;
	}
	cout << (ans == 1 ? "Persepolis" : ans == 2 ? "Esteghlal" : "Penalty") << "\n";
	return 0;
}
