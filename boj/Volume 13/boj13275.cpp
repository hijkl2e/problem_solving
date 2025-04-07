#include <bits/stdc++.h>

using namespace std;

vector<int> manacher(string &s) {
	int n = s.size();
	vector<int> p(n);
	int x{}, y{};
	for (int i = 0; i < n; ++i) {
		p[i] = y < i ? 0 : min(y - i + 1, p[2 * x - i]);
		while (i - p[i] >= 0 && i + p[i] < n && s[i - p[i]] == s[i + p[i]]) {
			++p[i];
		}
		if (i + p[i] - 1 > y) {
			x = i, y = i + p[i] - 1;
		}
	}
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	string T(2 * S.size() + 1, '#');
	for (int i = 0; i < S.size(); ++i) {
		T[2 * i + 1] = S[i];
	}
	vector<int> p = manacher(T);
	int ans = *max_element(p.begin(), p.end()) - 1;
	cout << ans << "\n";
	return 0;
}
