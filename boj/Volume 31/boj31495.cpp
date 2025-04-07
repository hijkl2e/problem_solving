#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	if (S.size() > 2 && S.front() == '"' && S.back() == '"') {
		cout << S.substr(1, S.size() - 2) << "\n";
	} else {
		cout << "CE\n";
	}
	return 0;
}
