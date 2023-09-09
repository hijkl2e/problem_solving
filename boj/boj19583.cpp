#include <bits/stdc++.h>

using namespace std;

int solve() {
	int m{}, s{};
	char c{};
	if (cin >> m >> c >> s) {
		return 60 * m + s;
	} else {
		return -1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int S = solve();
	int E = solve();
	int Q = solve();
	set<string> s1, s2;
	int t{};
	while ((t = solve()) != -1) {
		string s;
		cin >> s;
		if (t <= S) {
			s1.insert(s);
		} else if (E <= t && t <= Q) {
			s2.insert(s);
		}
	}
	vector<string> A;
	set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(A));
	cout << A.size() << "\n";
	return 0;
}
