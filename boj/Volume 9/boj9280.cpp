#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string let = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_,.?";
	vector<string> morse{
		".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
		"-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
		"..-", "...-", ".--", "-..-", "-.--", "--..", "..--", ".-.-", "---.", "----"
	};
	map<char, string> l2m;
	map<string, char> m2l;
	for (int i = 0; i < let.size(); ++i) {
		l2m[let[i]] = morse[i];
		m2l[morse[i]] = let[i];
	}
	string S;
	while (getline(cin, S)) {
		string T;
		vector<int> A(S.size());
		for (int i = 0; i < S.size(); ++i) {
			T += l2m[S[i]];
			A[i] = l2m[S[i]].size();
		}
		reverse(A.begin(), A.end());
		for (int i = 0, j = 0; i < A.size(); ++i) {
			cout << m2l[T.substr(j, A[i])];
			j += A[i];
		}
		cout << "\n";
	}
	return 0;
}
