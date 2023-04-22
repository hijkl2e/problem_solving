#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<string> A;
	string s;
	for (int i = 0; i < S.size(); ++i) {
		char c = S[i];
		if (c == '<' || c == '>' || c == '&' || c == '|' || c == '(' || c == ')' || c == ' ') {
			if (s.size()) {
				A.push_back(s);
				s.clear();
			}
			if (c == '&' || c == '|') {
				A.push_back(string(2, c));
				++i;
			} else if (c != ' ') {
				A.push_back(string(1, c));
			}
		} else {
			s += c;
		}
	}
	if (s.size()) {
		A.push_back(s);
	}
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << (i == A.size() - 1 ? "\n" : " ");
	}
	return 0;
}
