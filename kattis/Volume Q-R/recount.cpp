#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, int> freq;
	string s;
	while (getline(cin, s), s != "***") {
		++freq[s];
	}
	vector<string> A;
	int maxv{};
	for (auto &p : freq) {
		if (maxv < p.second) {
			A.clear();
			A.push_back(p.first);
			maxv = p.second;
		} else if (maxv == p.second) {
			A.push_back(p.first);
		}
	}
	cout << (A.size() == 1 ? A[0] : "Runoff!") << "\n";
	return 0;
}
