#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cin.ignore();
		string s;
		getline(cin, s);
		int ans{};
		vector<int> B(10);
		for (int i = 0; i < s.size(); ++i) {
			fill(B.begin(), B.end(), 0);
			int cnt{}, maxv{};
			for (int j = 0; j < 100 && i + j < s.size(); ++j) {
				int val = ++B[s[i + j] - '0'];
				if (val == 1) {
					++cnt;
				}
				maxv = max(maxv, val);
				if (maxv <= cnt) {
					++ans;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
