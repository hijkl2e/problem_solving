#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	map<string, set<string>> c2s;
	while (N--) {
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		c2s[s3].insert(s1 + "#" + s2);
	}
	for (auto &p : c2s) {
		cout << p.first << " " << p.second.size() << "\n";
	}
	return 0;
}
