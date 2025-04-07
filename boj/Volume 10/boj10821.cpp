#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	cout << count(S.begin(), S.end(), ',') + 1 << "\n";
	return 0;
}
