#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	bool yes = accumulate(S.begin(), S.begin() + S.size() / 2, 0)
			== accumulate(S.begin() + S.size() / 2, S.end(), 0);
	cout << (yes ? "LUCKY" : "READY") << "\n";
	return 0;
}
