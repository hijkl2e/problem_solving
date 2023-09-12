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
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	string T(2 * N + 1, '#');
	for (int i = 0; i < N; ++i) {
		T[2 * i + 1] = S[i];
	}
	vector<int> p = manacher(T);
	int ans{};
	for (int i = 0; i < T.size(); ++i) {
		if (p[i] == T.size() - i) {
			ans = N - p[i] + 1;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
