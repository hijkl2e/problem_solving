#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{};
	cin >> M;
	map<string, int> s2x;
	while (M--) {
		string s;
		int x{};
		cin >> s >> x;
		s2x[s] += x;
	}
	map<int, int> freq;
	for (auto &p : s2x) {
		++freq[p.second];
	}
	bool yes{};
	for (auto &p : freq) {
		int x = p.first * 1.618;
		auto it = freq.find(x);
		yes |= it != freq.end() && it->second > (x == p.first);
	}
	cout << (yes ? "Delicious!" : "Not Delicious...") << "\n";
	return 0;
}
