#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, int> s2g1 {
		{'A', 4}, {'B', 3}, {'C', 2}, {'D', 1}, {'F', 0}
	};
	map<char, int> s2g2 {
		{'+', 3}, {'0', 0}, {'-', -3}
	};
	string S;
	cin >> S;
	S += '0';
	int ans = 10 * s2g1[S[0]] + s2g2[S[1]];
	cout << ans / 10 << "." << ans % 10 << "\n";
	return 0;
}
