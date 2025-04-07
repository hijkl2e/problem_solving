#include <bits/stdc++.h>

using namespace std;

vector<int> get_pi(string &s) {
	vector<int> pi(s.size());
	for (int i = 1; i < pi.size(); ++i) {
		int j = pi[i - 1];
		while (j && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}

vector<int> kmp(string &s, string &p) {
	vector<int> ret;
	vector<int> pi = get_pi(p);
	for (int i = 0, j = 0; i < s.size(); ++i) {
		while (j && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j] && ++j == p.size()) {
			ret.push_back(i - j + 1);
			j = pi[j - 1];
		}
	}
	return ret;
}

string solve(string &S) {
	string ret;
	for (char c : S) {
		if (isalpha(c)) {
			ret += c;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S, T;
	getline(cin, S);
	getline(cin, T);
	S = solve(S);
	cout << (kmp(S, T).size() ? 1 : 0) << "\n";
	return 0;
}
