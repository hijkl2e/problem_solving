#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	sort(s1.begin(), s1.end());
	sort(s2.rbegin(), s2.rend());
	int n = s1.size();
	string ans(n, 'X');
	int p = -1;
	for (int i = 0; i < n; ++i) {
		char c1 = s1[(i + 1) / 2];
		char c2 = s2[i / 2];
		ans[i] = i % 2 ? c2 : c1;
		if (p == -1 && c1 >= c2) {
			p = i;
		}
	}
	if (p != -1 && (n + p) % 2 == 0) {
		for (int i = p; i < n; i += 2) {
			swap(ans[i], ans[i + 1]);
		}
	}
	cout << ans << "\n";
	return 0;
}
