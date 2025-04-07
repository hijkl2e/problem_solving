#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		string name, date1, date2;
		int courses{};
		cin >> name >> date1 >> date2 >> courses;
		int year1 = stoi(date1.substr(0, 4));
		int year2 = stoi(date2.substr(0, 4));
		cout << name << " ";
		if (year1 >= 2010 || year2 >= 1991) {
			cout << "eligible\n";
		} else if (courses > 40) {
			cout << "ineligible\n";
		} else {
			cout << "coach petitions\n";
		}
	}
	return 0;
}
