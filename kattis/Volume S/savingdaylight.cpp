#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string y, m, d;
	while (cin >> y >> m >> d) {
		int m1{}, s1{}, m2{}, s2{};
		char c{};
		cin >> m1 >> c >> s1;
		cin >> m2 >> c >> s2;
		int time = (m2 - m1) * 60 + (s2 - s1);
		cout << y << " " << m << " " << d << " " << time / 60 << " hours " << time % 60 << " minutes\n";
	}
	return 0;
}
