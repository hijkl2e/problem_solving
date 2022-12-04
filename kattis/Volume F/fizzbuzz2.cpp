#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	ii ans{-1, -1};
	for (int i = 1; i <= N; ++i) {
		int cnt{};
		for (int j = 1; j <= M; ++j) {
			string ans;
			if (j % 15 == 0) {
				ans = "fizzbuzz";
			} else if (j % 3 == 0) {
				ans = "fizz";
			} else if (j % 5 == 0) {
				ans = "buzz";
			} else {
				ans = to_string(j);
			}
			string s;
			cin >> s;
			if (s == ans) {
				++cnt;
			}
		}
		if (ans.second < cnt) {
			ans = {i, cnt};
		}
	}
	cout << ans.first << "\n";
	return 0;
}
