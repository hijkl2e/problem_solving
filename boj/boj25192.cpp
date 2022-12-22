#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	set<string> S;
	int ans{};
	while (N--) {
		string s;
		getline(cin, s);
		if (s == "ENTER") {
			S.clear();
			continue;
		}
		if (S.insert(s).second) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
