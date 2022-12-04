#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	set<string> S;
	while (S.size() < 12) {
		string s1, s2;
		cin >> s1 >> s2;
		if (S.insert(s1).second) {
			cout << s1 << " " << s2 << "\n";
		}
	}
	return 0;
}
