#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, int> g2p{
		{"A+", 45}, {"A0", 40}, {"B+", 35}, {"B0", 30},
		{"C+", 25}, {"C0", 20}, {"D+", 15}, {"D0", 10}, {"F", 0}
	};
	int x{}, y{};
	for (int i = 0; i < 20; ++i) {
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		if (s3 == "P") {
			continue;
		}
		int z = s2[0] - '0';
		x += z * g2p[s3];
		y += z;
	}
	double ans = x / 10.0 / y;
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
