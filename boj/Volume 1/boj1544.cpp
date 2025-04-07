#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	set<string> S;
	while (N--) {
		string s;
		getline(cin, s);
		string mins = s;
		int l = s.size();
		s += s;
		for (int i = 1; i < l; ++i) {
			if (mins > s.substr(i, l)) {
				mins = s.substr(i, l);
			}
		}
		S.insert(mins);
	}
	cout << S.size() << "\n";
	return 0;
}
