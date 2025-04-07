#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		int ans{};
		for (int i = 0; i < s1.size(); ++i) {
			ans += s1[i] ^ s2[i];
		}
		cout << "Hamming distance is " << ans << ".\n";
	}
	return 0;
}
