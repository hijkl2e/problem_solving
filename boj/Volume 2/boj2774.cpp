#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	set<int> S;
	while (T--) {
		string s;
		getline(cin, s);
		S.clear();
		for (char c : s) {
			S.insert(c - '0');
		}
		cout << S.size() << "\n";
	}
	return 0;
}
