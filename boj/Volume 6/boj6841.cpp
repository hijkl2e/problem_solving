#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, string> D{
		{"CU", "see you"}, {":-)", "I’m happy"},
		{":-(", "I’m unhappy"}, {";-)", "wink"},
		{":-P", "stick out my tongue"}, {"(~.~)", "sleepy"},
		{"TA", "totally awesome"}, {"CCC", "Canadian Computing Competition"},
		{"CUZ", "because"}, {"TY", "thank-you"},
		{"YW", "you’re welcome"}, {"TTYL", "talk to you later"}
	};
	string S;
	while (S != "TTYL" && getline(cin, S)) {
		auto it = D.find(S);
		if (it == D.end()) {
			cout << S << "\n";
		} else {
			cout << it->second << "\n";
		}
	}
	return 0;
}
