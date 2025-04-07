#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	cout << (S.find("ss") == -1 ? "no hiss" : "hiss") << "\n";
	return 0;
}
