#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int h1{}, m1{}, s1{};
	int h2{}, m2{}, s2{};
	char c{};
	cin >> h1 >> c >> m1 >> c >> s1;
	cin >> h2 >> c >> m2 >> c >> s2;
	int t1 = 3600 * h1 + 60 * m1 + s1;
	int t2 = 3600 * h2 + 60 * m2 + s2;
	int t3 = (t2 - t1 + 86400) % 86400;
	if (t3 == 0) {
		t3 = 86400;
	}
	int h3 = t3 / 3600;
	int m3 = t3 % 3600 / 60;
	int s3 = t3 % 60;
	cout << setw(2) << setfill('0') << h3 << ":";
	cout << setw(2) << setfill('0') << m3 << ":";
	cout << setw(2) << setfill('0') << s3 << "\n";
	return 0;
}
