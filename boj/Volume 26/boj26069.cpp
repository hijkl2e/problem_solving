#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	map<string, bool> n2d;
	while (N--) {
		string s1, s2;
		cin >> s1 >> s2;
		bool yes = s1 == "ChongChong" || s2 == "ChongChong" || n2d[s1] || n2d[s2];
		n2d[s1] = n2d[s2] = yes;
	}
	int ans{};
	for (auto &p : n2d) {
		ans += p.second;
	}
	cout << ans << "\n";
	return 0;
}
