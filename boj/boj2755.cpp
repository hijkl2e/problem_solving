#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, int> s2g1 {
		{'A', 4}, {'B', 3}, {'C', 2}, {'D', 1}, {'F', 0}
	};
	map<char, int> s2g2 {
		{'+', 3}, {'0', 0}, {'-', -3}
	};
	int N{}, X{}, Y{};
	cin >> N;
	while (N--) {
		string s;
		int x{};
		cin >> s >> x >> s;
		Y += x * (10 * s2g1[s[0]] + s2g2[s[1]]);
		X += x;
	}
	double ans = Y / 10.0 / X + EPS;
	cout << fixed << setprecision(2);
	cout << ans << "\n";
	return 0;
}
