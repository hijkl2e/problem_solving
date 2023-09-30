#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	set<string> S{
		"Never gonna give you up", "Never gonna let you down",
		"Never gonna run around and desert you", "Never gonna make you cry",
		"Never gonna say goodbye", "Never gonna tell a lie and hurt you",
		"Never gonna stop"
	};
	int N{};
	cin >> N;
	cin.ignore();
	bool yes{};
	while (N--) {
		string s;
		getline(cin, s);
		if (S.find(s) == S.end()) {
			yes = true;
			break;
		}
	}
	cout << (yes ? "Yes" : "No") << "\n";
	return 0;
}
