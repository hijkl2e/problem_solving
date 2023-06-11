#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	map<string, int> d2c;
	map<string, string> d2n;
	while (N--) {
		string s1, s2;
		int x{};
		cin >> s1 >> x >> s2;
		int &y = d2c.insert({s2, -1}).first->second;
		if (y < x) {
			y = x;
			d2n[s2] = s1;
		}
	}
	vector<string> A;
	for (auto &p : d2n) {
		A.push_back(p.second);
	}
	sort(A.begin(), A.end());
	cout << A.size() << "\n";
	for (auto &s : A) {
		cout << s << "\n";
	}
	return 0;
}
