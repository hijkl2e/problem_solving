#include <bits/stdc++.h>

using namespace std;

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
	cout << (S.find(T) != -1) << "\n";
	return 0;
}
