#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	set<string> S;
	while (N--) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s2 == "enter") {
			S.insert(s1);
		} else {
			S.erase(S.find(s1));
		}
	}
	auto it = S.rbegin();
	while (it != S.rend()) {
		cout << *it++ << "\n";
	}
	return 0;
}
