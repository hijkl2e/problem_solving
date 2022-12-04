#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	set<string> S;
	char prev{};
	int ans{};
	for (int i = 0; i < N; ++i) {
		string s;
		getline(cin, s);
		if (S.count(s) || (prev && prev != s.front())) {
			ans = i % 2 + 1;
			break;
		}
		S.insert(s);
		prev = s.back();
	}
	if (ans) {
		cout << "Player " << ans << " lost\n";
	} else {
		cout << "Fair Game\n";
	}
	return 0;
}
