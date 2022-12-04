#include <bits/stdc++.h>

using namespace std;

using ss = pair<string, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ss> A;
	map<string, int> B;
	string s1, s2;
	while (cin >> s1 >> s2) {
		A.push_back({s2, s1});
		++B[s1];
	}
	sort(A.begin(), A.end());
	for (auto &p : A) {
		cout << p.second;
		if (B[p.second] > 1) {
			cout << " " << p.first;
		}
		cout << "\n";
	}
	return 0;
}
