#include <bits/stdc++.h>

using namespace std;

void replace(string &S, const string &P, const string &T) {
	int p = -1;
	while ((p = S.find(P, p + 1)) != -1) {
		S.replace(S.begin() + p, S.begin() + p + P.size(), T);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<char, char> tab{
		{'@', 'a'}, {'[', 'c'}, {'!', 'i'}, {';', 'j'}, {'^', 'n'},
		{'0', 'o'}, {'7', 't'}, {'v', 'v'}, {'w', 'w'}
	};
	int N{};
	cin >> N;
	cin.ignore();
	while (N--) {
		string S;
		getline(cin, S);
		replace(S, "\\\\'", "w");
		replace(S, "\\'", "v");
		int cnt{};
		for (auto &c : S) {
			auto it = tab.find(c);
			if (it != tab.end()) {
				c = it->second;
				++cnt;
			}
		}
		if (cnt < (S.size() + 1) / 2) {
			cout << S << "\n";
		} else {
			cout << "I don't understand\n";
		}
	}
	return 0;
}
