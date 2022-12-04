#include <bits/stdc++.h>

using namespace std;

using is = pair<int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		map<string, int> A;
		int N{};
		cin >> N;
		while (N--) {
			string s;
			int x{};
			cin >> s >> x;
			A[s] += x;
		}
		vector<is> B;
		for (auto &p : A) {
			B.push_back({-p.second, p.first});
		}
		sort(B.begin(), B.end());
		cout << B.size() << "\n";
		for (auto &p : B) {
			cout << p.second << " " << -p.first << "\n";
		}
	}
	return 0;
}
