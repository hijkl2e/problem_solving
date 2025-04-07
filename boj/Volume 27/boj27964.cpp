#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	set<string> S;
	while (N--) {
		string s;
		cin >> s;
		if (s.size() >= 6 && s.substr(s.size() - 6) == "Cheese") {
			S.insert(s);
		}
	}
	cout << (S.size() >= 4 ? "yummy" : "sad") << "\n";
	return 0;
}
