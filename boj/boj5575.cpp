#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 3; ++i) {
		int h1{}, m1{}, s1{}, h2{}, m2{}, s2{};
		cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
		int t1 = 3600 * h1 + 60 * m1 + s1;
		int t2 = 3600 * h2 + 60 * m2 + s2;
		int d = t2 - t1;
		cout << d / 3600 << " " << d % 3600 / 60 << " " << d % 60 << "\n";
	}
	return 0;
}
