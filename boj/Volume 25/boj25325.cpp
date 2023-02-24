#include <bits/stdc++.h>

using namespace std;

using is = pair<int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	map<string, int> freq;
	while (N--) {
		string s;
		cin >> s;
		freq[s] = 0;
	}
	string s;
	while (cin >> s) {
		++freq[s];
	}
	vector<is> A;
	for (auto &p : freq) {
		A.push_back({-p.second, p.first});
	}
	sort(A.begin(), A.end());
	for (auto &p : A) {
		cout << p.second << " " << -p.first << "\n";
	}
	return 0;
}
