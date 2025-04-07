#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	map<string, int> freq;
	while (N--) {
		string s;
		getline(cin, s);
		++freq[s];
	}
	string ans;
	int cnt{};
	for (auto &p : freq) {
		if (cnt < p.second) {
			ans = p.first;
			cnt = p.second;
		}
	}
	cout << ans << "\n";
	return 0;
}
