#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int ans{}, p{};
	while (s1.find(s2, p) != -1) {
		p = s1.find(s2, p) + s2.size();
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
