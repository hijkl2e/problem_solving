#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	string T = S;
	reverse(T.begin(), T.end());
	cout << (S == T) << "\n";
	return 0;
}
