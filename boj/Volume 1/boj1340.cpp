#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> month{
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};
	vector<int> day{
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	string S;
	getline(cin, S);
	istringstream iss(S);
	int M{}, D{}, Y{}, h{}, m{};
	char c{};
	iss >> S >> D >> c >> Y >> h >> c >> m;
	M = find(month.begin(), month.end(), S) - month.begin() + 1;
	bool leap = (Y % 4 == 0 && Y % 100) || Y % 400 == 0;
	int total = (leap ? 366 : 365) * 1440;
	day[1] += leap;
	int elapsed = (accumulate(day.begin(), day.begin() + M - 1, 0) + D - 1) * 1440 + h * 60 + m;
	double ans = elapsed * 100.0 / total;
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
