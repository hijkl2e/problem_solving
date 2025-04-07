#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		string s = to_string(N);
		int sum = accumulate(s.begin(), s.end(), 0) - s.size() * '0';
		int ans{};
		for (int i = 11;; ++i) {
			s = to_string(N * i);
			if (accumulate(s.begin(), s.end(), 0) - s.size() * '0' == sum) {
				ans = i;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
