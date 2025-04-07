#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, int> tz2i{
		{"UTC", 0}, {"GMT", 0}, {"BST", 2}, {"IST", 2},
		{"WET", 0}, {"WEST", 2}, {"CET", 2}, {"CEST", 4},
		{"EET", 4}, {"EEST", 6}, {"MSK", 6}, {"MSD", 8},
		{"AST", -8}, {"ADT", -6}, {"NST", -7}, {"NDT", -5},
		{"EST", -10}, {"EDT", -8}, {"CST", -12}, {"CDT", -10},
		{"MST", -14}, {"MDT", -12}, {"PST", -16}, {"PDT", -14},
		{"HST", -20}, {"AKST", -18}, {"AKDT", -16}, {"AEST", 20},
		{"AEDT", 22}, {"ACST", 19}, {"ACDT", 21}, {"AWST", 16}
	};
	int T{};
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int time{};
		if (s == "midnight") {
			time = 0;
		} else if (s == "noon") {
			time = 60 * 12;
		} else {
			istringstream iss(s);
			int h{}, m{};
			char c{};
			iss >> h >> c >> m;
			h %= 12;
			cin >> s;
			if (s == "p.m.") {
				h += 12;
			}
			time = 60 * h + m;
		}
		string tz1, tz2;
		cin >> tz1 >> tz2;
		int d = (tz2i[tz2] - tz2i[tz1] + 48) % 48;
		time = (time + 30 * d) % 1440;
		if (time == 0) {
			cout << "midnight\n";
		} else if (time == 60 * 12) {
			cout << "noon\n";
		} else {
			int h = time / 60;
			int m = time % 60;
			cout << (h % 12 == 0 ? 12 : h % 12) << ":" << setfill('0') << setw(2) << m << " ";
			cout << (h < 12 ? "a.m." : "p.m.") << "\n";
		}
	}
	return 0;
}
