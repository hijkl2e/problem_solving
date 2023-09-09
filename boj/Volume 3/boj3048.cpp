#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	string s1, s2;
	cin >> s1 >> s2;
	int t{};
	cin >> t;
	for (int i = 0; i < N; ++i) {
		s2.insert(s2.begin() + min(max(t - i, 0), M), s1[i]);
	}
	cout << s2 << "\n";
	return 0;
}
