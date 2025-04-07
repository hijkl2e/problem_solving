#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int ans{};
	for (int i = 0; i < N; ++i) {
		if (s1[i] == s2[i]) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
