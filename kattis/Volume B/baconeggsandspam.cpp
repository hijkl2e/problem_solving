#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		cin.ignore();
		map<string, vector<string>> m2w;
		while (N--) {
			string s;
			getline(cin, s);
			istringstream iss(s);
			string s1, s2;
			iss >> s1;
			while (iss >> s2) {
				m2w[s2].push_back(s1);
			}
		}
		for (auto &[u, v] : m2w) {
			sort(v.begin(), v.end());
			cout << u;
			for (auto &s : v) {
				cout << " " << s;
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}
