#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	string x = "2023";
	int ans{};
	for (int i = 1; i <= N; ++i) {
		string s = to_string(i);
		int k{};
		for (int j = 0; j < s.size() && k < x.size(); ++j) {
			if (s[j] == x[k]) {
				++k;
			}
		}
		if (k == 4) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
