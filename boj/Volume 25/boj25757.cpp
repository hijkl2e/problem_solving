#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, int> g2i{
		{'Y', 1}, {'F', 2}, {'O', 3}
	};
	int N{};
	char G{};
	cin >> N >> G;
	cin.ignore();
	int x = g2i[G];
	set<string> nset;
	while (N--) {
		string s;
		getline(cin, s);
		nset.insert(s);
	}
	int ans = nset.size() / x;
	cout << ans << "\n";
	return 0;
}
