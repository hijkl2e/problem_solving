#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S), S != "#") {
		int cnt = count(S.begin(), S.end(), S[0]) + count(S.begin(), S.end(), toupper(S[0])) - 1;
		cout << S[0] << " " << cnt << "\n";
	}
	return 0;
}
