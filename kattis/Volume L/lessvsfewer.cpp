#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	set<string> C{
		"number", "most", "fewest", "more", "fewer", "many", "few"
	};
	set<string> M{
		"amount", "most", "least", "more", "less", "much", "little"
	};
	int N{}, P{};
	cin >> N >> P;
	map<string, char> n2t;
	while (N--) {
		string s;
		char c{};
		cin >> s >> c;
		n2t[s] = c;
	}
	cin.ignore();
	while (P--) {
		string s, n;
		getline(cin, s);
		istringstream iss(s);
		iss >> s >> n >> n;
		bool yes = n2t[n] == 'c' ? C.count(s) : M.count(s);
		cout << (yes ? "Correct!" : "Not on my watch!") << "\n";
	}
	return 0;
}
