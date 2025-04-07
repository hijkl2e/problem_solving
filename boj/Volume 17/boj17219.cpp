#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	map<string, string> s2p;
	while (N--) {
		string s, p;
		cin >> s >> p;
		s2p[s] = p;
	}
	while (M--) {
		string s;
		cin >> s;
		cout << s2p[s] << "\n";
	}
	return 0;
}
