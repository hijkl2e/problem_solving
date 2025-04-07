#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string s1;
		getline(cin, s1);
		string s2 = s1;
		reverse(s2.begin(), s2.end());
		cout << s1 << s2 << "\n";
	}
	return 0;
}
