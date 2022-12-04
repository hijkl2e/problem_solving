#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		cin.ignore();
		vector<vector<string>> A(128);
		ii ans;
		while (N--) {
			string S;
			getline(cin, S);
			int res{};
			for (char c : S) {
				res ^= c;
			}
			A[res].push_back(S);
		}
		for (auto &v : A) {
			sort(v.begin(), v.end());
			for (auto &s : v) {
				ans.second += v.end() - upper_bound(v.begin(), v.end(), s);
			}
			ans.first += unique(v.begin(), v.end()) - v.begin();
		}
		cout << ans.first << " " << ans.second << "\n";
	}
	return 0;
}
