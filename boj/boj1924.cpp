#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> wday{
		"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"
	};
	int x{}, y{};
	cin >> x >> y;
	tm time{};
	time.tm_year = 2007 - 1900;
	time.tm_mon = x - 1;
	time.tm_mday = y;
	mktime(&time);
	string ans = wday[time.tm_wday];
	cout << ans << "\n";
	return 0;
}
