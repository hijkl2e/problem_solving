#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int y{};
	cin >> y;
	tm time{};
	time.tm_year = y - 1900;
	time.tm_mon = 4;
	time.tm_mday = 1;
	mktime(&time);
	cout << (time.tm_wday && time.tm_wday < 5 ? 5 : 6) << " weeks\n";
	return 0;
}
