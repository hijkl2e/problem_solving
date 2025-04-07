#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string aeiou = "aeiou";
	string S;
	while (getline(cin, S), S != "#") {
		for (int i = 0; i < S.size(); ++i) {
			if (aeiou.find(S[i]) != -1) {
				rotate(S.begin(), S.begin() + i, S.end());
				break;
			}
		}
		cout << S << "ay\n";
	}
	return 0;
}
