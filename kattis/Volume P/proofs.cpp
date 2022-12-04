#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans{};
	unordered_set<string> S;
	for (int i = 1; i <= N; ++i) {
		string s;
		while (cin >> s, s != "->") {
			if (S.find(s) == S.end()) {
				ans = i;
				i = N;
				break;
			}
		}
		cin >> s;
		S.insert(s);
	}
	if (ans) {
		cout << ans << "\n";
	} else {
		cout << "correct\n";
	}
	return 0;
}
