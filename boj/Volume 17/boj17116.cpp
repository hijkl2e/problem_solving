#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	cin >> S;
	bool yes = S == "KEY" || S == "LONELY";
	cout << "BABA IS " << (yes ? "" : "NOT ") << "WIN\n";
	return 0;
}
