#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 1; cin >> N, N; ++tc) {
		cin.ignore();
		map<string, int> freq;
		while (N--) {
			string s;
			getline(cin, s);
			istringstream iss(s);
			while (iss >> s);
			for (auto &c : s) {
				c = tolower(c);
			}
			++freq[s];
		}
		cout << "List " << tc << ":\n";
		for (auto &p : freq) {
			cout << p.first << " | " << p.second << "\n";
		}
	}
	return 0;
}
