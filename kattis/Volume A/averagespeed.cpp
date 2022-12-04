#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int time{}, speed{};
	double dist{};
	string S;
	while (getline(cin, S)) {
		istringstream iss(S);
		int h{}, m{}, s{}, ns{};
		char c{};
		iss >> h >> c >> m >> c >> s;
		int now = 3600 * h + 60 * m + s;
		dist += (now - time) * speed / 3600.0;
		if (iss >> ns) {
			speed = ns;
		} else {
			cout << fixed << setprecision(2);
			cout << S << " " << dist << " km\n";
		}
		time = now;
	}
	return 0;
}
