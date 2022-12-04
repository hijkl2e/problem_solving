#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int P{}, N{};
	cin >> P >> N;
	cin.ignore();
	set<string> S;
	int ans{};
	for (int i = 1; i <= N; ++i) {
		string s;
		getline(cin, s);
		S.insert(s);
		if (S.size() == P) {
			ans = i;
			break;
		}
	}
	if (ans) {
		cout << ans << "\n";
	} else {
		cout << "paradox avoided\n";
	}
	return 0;
}
