#include <bits/stdc++.h>

using namespace std;

vector<int> solve(string &S) {
	static string fox = "the quick brown fox jumps over the lazy dog";
	if (S.size() != fox.size()) {
		return {};
	}
	vector<int> tab(123, -1);
	vector<int> rtab(123, -1);
	tab[' '] = rtab[' '] = ' ';
	for (int i = 0; i < fox.size(); ++i) {
		if ((tab[S[i]] == -1 || tab[S[i]] == fox[i])
				&& (rtab[fox[i]] == -1 || rtab[fox[i]] == S[i])) {
			tab[S[i]] = fox[i];
			rtab[fox[i]] = S[i];
		} else {
			return {};
		}
	}
	return tab;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	vector<string> A;
	while (getline(cin, S)) {
		A.push_back(S);
	}
	vector<int> tab;
	for (auto &s : A) {
		tab = solve(s);
		if (tab.size()) {
			break;
		}
	}
	if (tab.empty()) {
		cout << "No solution.\n";
		return 0;
	}
	for (auto &s : A) {
		for (char c : s) {
			c = tab[c];
			cout << c;
		}
		cout << "\n";
	}
	return 0;
}
