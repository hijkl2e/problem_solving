#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	regex r("(100+1+|01)+");
	string S;
	getline(cin, S);
	cout << (regex_match(S, r) ? "SUBMARINE" : "NOISE") << "\n";
	return 0;
}
