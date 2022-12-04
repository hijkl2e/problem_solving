#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	set<string> S;
	while (N--) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1 == "entry") {
			cout << s2 << " entered" << (S.insert(s2).second ? "" : " (ANOMALY)") << "\n";
		} else {
			cout << s2 << " exited" << (S.erase(s2) ? "" : " (ANOMALY)") << "\n";	
		}
	}
	return 0;
}
