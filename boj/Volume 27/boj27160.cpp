#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	map<string, int> freq;
	while (N--) {
		string s;
		int x{};
		cin >> s >> x;
		freq[s] += x;
	}
	bool yes{};
	for (auto &p : freq) {
		yes |= p.second == 5;
	}
	cout << (yes ? "YES" : "NO") << "\n";
	return 0;
}
