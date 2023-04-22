#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	getline(cin, S);
	getline(cin, S);
	reverse(S.begin(), S.end());
	cout << S << "\n";
	return 0;
}
