#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	sort(S.begin(), S.end());
	cout << (unique(S.begin(), S.end()) == S.end()) << "\n";
	return 0;
}
