#include <bits/stdc++.h>

using namespace std;

using is = pair<int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	while (getline(cin, s1), s1[0] != '0') {
		map<string, vector<string>> A;
		while (getline(cin, s2), s2[0] != '1') {
			if (isupper(s2[0])) {
				A[s1 = s2];
				continue;
			}
			A[s1].push_back(s2);
		}
		map<string, int> B;
		for (auto &[u, v] : A) {
			sort(v.begin(), v.end());
			v.resize(unique(v.begin(), v.end()) - v.begin());
			for (auto &s : v) {
				++B[s];
			}
		}
		vector<is> C;
		for (auto &[u, v] : A) {
			int cnt{};
			for (auto &s : v) {
				cnt += B[s] == 1;
			}
			C.push_back({-cnt, u});
		}
		sort(C.begin(), C.end());
		for (auto &p : C) {
			cout << p.second << " " << -p.first << "\n";
		}
	}
	return 0;
}
