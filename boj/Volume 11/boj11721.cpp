#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	for (int i = 0; i < S.size(); i += 10) {
		cout << S.substr(i, 10) << "\n";
	}
	return 0;
}
