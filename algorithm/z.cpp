#include <bits/stdc++.h>

using namespace std;

vector<int> get_z(string &s) {
	int n = s.size();
	vector<int> z(n);
	int x{}, y{};
	for (int i = 1; i < n; ++i) {
		z[i] = y < i ? 0 : min(y - i + 1, z[i - x]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			++z[i];
		}
		if (i + z[i] - 1 > y) {
			x = i, y = i + z[i] - 1;
		}
	}
	return z;
}
