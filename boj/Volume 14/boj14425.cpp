#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	set<string> S;
	while (N--) {
		string s;
		getline(cin, s);
		S.insert(s);
	}
	int ans{};
	while (M--) {
		string s;
		getline(cin, s);
		ans += S.count(s);
	}
	cout << ans << "\n";
	return 0;
}
