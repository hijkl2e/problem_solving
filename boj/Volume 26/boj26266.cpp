#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	vector<int> A(s1.size());
	for (int i = 0; i < s1.size(); ++i) {
		A[i] = (s2[i] - s1[i] + 26) % 26;
	}
	int x = s1.size();
	for (int i = 1; i < s1.size(); ++i) {
		if (s1.size() % i) {
			continue;
		}
		bool yes = true;
		for (int j = 0; j < s1.size(); ++j) {
			if (A[j] != A[j % i]) {
				yes = false;
				break;
			}
		}
		if (yes) {
			x = i;
			break;
		}
	}
	string ans;
	for (int i = 0; i < x; ++i) {
		char c = (A[i] + 25) % 26 + 'A';
		ans += c;
	}
	cout << ans << "\n";
	return 0;
}
