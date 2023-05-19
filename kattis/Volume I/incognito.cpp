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
		map<string, int> freq;
		while (N--) {
			string s1, s2;
			cin >> s1 >> s2;
			++freq[s2];
		}
		int ans = 1;
		for (auto &p : freq) {
			ans *= p.second + 1;
		}
		--ans;
		cout << ans << "\n";
	}
	return 0;
}
