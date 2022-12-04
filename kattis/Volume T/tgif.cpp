#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, int> m2i{
		{"JAN", 1}, {"FEB", 2}, {"MAR", 3}, {"APR", 4},
		{"MAY", 5}, {"JUN", 6}, {"JUL", 7}, {"AUG", 8},
		{"SEP", 9}, {"OCT", 10}, {"NOV", 11}, {"DEC", 12}
	};
	map<string, int> d2i{
		{"SUN", 0}, {"MON", 1}, {"TUE", 2}, {"WED", 3},
		{"THU", 4}, {"FRI", 5}, {"SAT", 6}
	};
	int D{};
	cin >> D;
	string s;
	cin >> s;
	int M = m2i[s];
	cin >> s;
	int day = d2i[s];
	tm time{};
	time.tm_year = 2000;
	time.tm_mday = 1;
	while (mktime(&time), time.tm_wday != day) {
		time.tm_year += 4;
	}
	time.tm_mon = M - 1;
	time.tm_mday = D;
	mktime(&time);
	if (M >= 3 && time.tm_wday >= 5) {
		cout << "not sure\n";
	} else if (time.tm_wday == 5) {
		cout << "TGIF\n";
	} else {
		cout << ":(\n";
	}
	return 0;
}
