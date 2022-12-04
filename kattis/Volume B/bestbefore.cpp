#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	istringstream iss(S);
	int A{}, B{}, C{};
	char c{};
	iss >> A >> c >> B >> c >> C;
	int ans_y{}, ans_m{}, ans_d{};
	ans_y = INF;
	for (int i = 0; i < 6; ++i) {
		int y = (A < 2000 ? 2000 + A : A) - 1900;
		int m = B - 1;
		int d = C;
		tm time{};
		time.tm_year = y;
		time.tm_mon = m;
		time.tm_mday = d;
		mktime(&time);
		if (time.tm_year == y && time.tm_mon == m && time.tm_mday == d) {
			if (y < ans_y || (y == ans_y && (m < ans_m || (m == ans_m && d < ans_d)))) {
				ans_y = y;
				ans_m = m;
				ans_d = d;
			}
		}
		swap(i % 2 ? A : B, C);
	}
	if (ans_y == INF) {
		cout << S << " is illegal\n";
	} else {
		ans_y += 1900;
		++ans_m;
		cout << setfill('0');
		cout << ans_y << "-" << setw(2) << ans_m << "-" << setw(2) << ans_d << "\n";
	}
	return 0;
}
