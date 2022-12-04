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
	vector<string> A;
	int minv = 1e9;
	for (auto &p : freq) {
		if (minv > p.second) {
			A.clear();
			A.push_back(p.first);
			minv = p.second;
		} else if (minv == p.second) {
			A.push_back(p.first);
		}
	}
	for (auto &s : A) {
		cout << s << "\n";
	}
	return 0;
}
