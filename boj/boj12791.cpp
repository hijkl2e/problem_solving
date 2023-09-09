#include <bits/stdc++.h>

using namespace std;

using is = pair<int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<is> A{
		{1967, "DavidBowie"}, {1969, "SpaceOddity"}, {1970, "TheManWhoSoldTheWorld"},
		{1971, "HunkyDory"}, {1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"},
		{1973, "AladdinSane"}, {1973, "PinUps"}, {1974, "DiamondDogs"}, {1975, "YoungAmericans"},
		{1976, "StationToStation"}, {1977, "Low"}, {1977, "Heroes"}, {1979, "Lodger"},
		{1980, "ScaryMonstersAndSuperCreeps"}, {1983, "LetsDance"}, {1984, "Tonight"},
		{1987, "NeverLetMeDown"}, {1993, "BlackTieWhiteNoise"}, {1995, "1.Outside"},
		{1997, "Earthling"}, {1999, "Hours"}, {2002, "Heathen"}, {2003, "Reality"},
		{2013, "TheNextDay"}, {2016, "BlackStar"}
	};
	int Q{};
	cin >> Q;
	while (Q--) {
		int s{}, e{};
		cin >> s >> e;
		auto beg = lower_bound(A.begin(), A.end(), make_pair(s, string("")));
		auto end = lower_bound(A.begin(), A.end(), make_pair(e + 1, string("")));
		cout << end - beg << "\n";
		while (beg != end) {
			cout << beg->first << " " << beg->second << "\n";
			++beg;
		}
	}
	return 0;
}
