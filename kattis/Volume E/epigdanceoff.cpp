#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	string s1, s2;
	getline(cin, s1);
	while (--N) {
		getline(cin, s2);
		for (int i = 0; i < M; ++i) {
			s1[i] |= s2[i];
		}
	}
	int ans = count(s1.begin(), s1.end(), '_') + 1;
	cout << ans << "\n";
	return 0;
}
