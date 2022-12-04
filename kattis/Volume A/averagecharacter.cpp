#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	char c = accumulate(S.begin(), S.end(), 0) / S.size();
	cout << c << "\n";
	return 0;
}
