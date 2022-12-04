#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	bool yes = S.size() % 2 == 0 && S[S.size() / 2] == ')';
	cout << (yes ? "correct" : "fix") << "\n";
	return 0;
}
