#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, int> m2i{
		{"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4},
		{"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8},
		{"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
	};
	vector<string> sign{
		"Capricorn", "Aquarius", "Pisces", "Aries",
		"Taurus", "Gemini", "Cancer", "Leo", "Virgo",
		"Libra", "Scorpio", "Sagittarius", "Capricorn"
	};
	vector<ii> birth{
		{1, 20}, {2, 19}, {3, 20}, {4, 20}, {5, 20}, {6, 21}, {7, 22},
		{8, 22}, {9, 21}, {10, 22}, {11, 22}, {12, 21}, {12, 31}
	};
	int T{};
	cin >> T;
	while (T--) {
		int d{};
		string M;
		cin >> d >> M;
		int m = m2i[M];
		int idx = lower_bound(birth.begin(), birth.end(), make_pair(m, d)) - birth.begin();
		cout << sign[idx] << "\n";
	}
	return 0;
}
