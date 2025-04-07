#include <bits/stdc++.h>

using namespace std;

using ic = pair<int, char>;

bool solve(set<ic> &S, set<ic>::iterator it, string &P) {
	for (int i = 0; i < P.size(); ++i, ++it) {
		if (it == S.end() || it->second != P[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string P, T;
	getline(cin, P);
	getline(cin, T);
	set<int> s1;
	for (int i = 0; i < T.size(); ++i) {
		if (T.substr(i, P.size()) == P) {
			s1.insert(s1.end(), i);
		}
	}
	set<ic> s2;
	for (int i = 0; i < T.size(); ++i) {
		s2.insert(s2.end(), {i, T[i]});
	}
	int N{};
	cin >> N;
	while (N--) {
		char c{};
		cin >> c;
		if (s1.empty()) {
			continue;
		}
		int x = c == 'L' ? *s1.begin() : *--s1.end();
		auto it = s2.find({x, T[x]});
		for (int i = 0; i < P.size(); ++i) {
			s1.erase(it->first);
			it = s2.erase(it);
		}
		for (int i = 0; i < P.size() && it != s2.begin(); ++i) {
			if (solve(s2, --it, P)) {
				s1.insert(it->first);
			} else {
				s1.erase(it->first);
			}
		}
	}
	string S;
	auto it = s2.begin();
	while (it != s2.end()) {
		S += it++->second;
	}
	cout << (T.size() - S.size()) / P.size() << "\n";
	cout << S << "\n";
	cout << (s1.size() ? "You Lose!" : "Perfect!") << "\n";
	return 0;
}
