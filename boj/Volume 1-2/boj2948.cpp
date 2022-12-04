#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> wday{
		"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
	};
	int D{}, M{};
	cin >> D >> M;
	tm time{};
	time.tm_year = 2009 - 1900;
	time.tm_mon = M - 1;
	time.tm_mday = D;
	mktime(&time);
	cout << wday[time.tm_wday] << "\n";
	return 0;
}
