#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		cin.ignore();
		set<string> S;
		while (N--) {
			string s;
			getline(cin, s);
			S.insert(s);
		}
		cout << S.size() << "\n";
	}
	return 0;
}
