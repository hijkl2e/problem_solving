#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	cout << (S.find("D2") == -1 && S.find("d2") == -1 ? "unrated" : "D2") << "\n";
	return 0;
}
