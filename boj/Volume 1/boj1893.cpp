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

vector<int> kmp(string &s, string &p, vector<int> &pi) {
	vector<int> ret;
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	vector<char> A(123);
	while (T--) {
		string S, T, U;
		getline(cin, S);
		getline(cin, T);
		getline(cin, U);
		for (int i = 0; i < S.size(); ++i) {
			int j = (i + S.size() - 1) % S.size();
			A[S[i]] = S[j];
		}
		vector<int> pi = get_pi(T);
		vector<int> B;
		for (int i = 0; i < S.size(); ++i) {
			if (kmp(U, T, pi).size() == 1) {
				B.push_back(i);
			}
			for (auto &c : U) {
				c = A[c];
			}
		}
		if (B.empty()) {
			cout << "no solution";
		} else if (B.size() == 1) {
			cout << "unique: " << B[0];
		} else {
			cout << "ambiguous:";
			for (int x : B) {
				cout << " " << x;
			}
		}
		cout << "\n";
	}
	return 0;
}
