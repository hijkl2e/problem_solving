#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> sound{
		"clank", "bong", "click", "tap", "poing", "clonk",
		"clack", "ping", "tip", "cloing", "tic", "cling",
		"bing", "pong", "clang", "pang", "clong", "tac",
		"boing", "boink", "cloink", "rattle", "clock", "toc",
		"clink", "tuc"
	};
	map<string, char> s2c;
	for (int i = 0; i < 26; ++i) {
		s2c[sound[i]] = i + 'a';
	}
	bool capslock{}, shift{};
	string text;
	int N{};
	cin >> N;
	while (N--) {
		string S;
		cin >> S;
		if (S == "whack") {
			text += " ";
		} else if (S == "bump") {
			capslock ^= true;
		} else if (S == "pop") {
			if (text.size()) {
				text.erase(text.size() - 1);
			}
		} else if (S == "dink") {
			shift = true;
		} else if (S == "thumb") {
			shift = false;
		} else {
			char c = s2c[S];
			if (capslock ^ shift) {
				c = toupper(c);
			}
			text += c;
		}
	}
	cout << text << "\n";
	return 0;
}
